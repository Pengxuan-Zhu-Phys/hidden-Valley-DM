/*====== Modules ===============
   Keys to switch on
   various modules of micrOMEGAs
================================*/

#define MASSES_INFO
/* Display information about mass spectrum  */

#define CONSTRAINTS

#define OMEGA /*  Calculate Freeze out relic density and display contribution of  individual channels */

#define INDIRECT_DETECTION
/* Compute spectra of gamma/positron/antiprotons/neutrinos for DM annihilation;
   Calculate <sigma*v>;
   Integrate gamma signal over DM galactic squared density for given line
   of sight;
   Calculate galactic propagation of positrons and antiprotons.
*/

#define CDM_NUCLEON
/* Calculate amplitudes and cross-sections for  CDM-mucleon collisions */

#define CDM_NUCLEUS
// Calculate  exclusion rate for direct detection experiments Xenon1T, DarkSide50, CRESST, and PICO

#define DECAYS

/*===== end of Modules  ======*/

/*===== Options ========*/
#define CLEAN
/*===== End of DEFINE  settings ===== */

#include "../include/micromegas.h"
#include "../include/micromegas_aux.h"
#include "lib/pmodel.h"
#include <json/json.h>
#include <fstream>
#include <cstring>
#include <iostream>

Json::Value getDecayBlock(const std::string &pname)
{
    Json::Value decayBlock(Json::objectValue);
    txtList L;
    char name[100];
    strncpy(name, pname.c_str(), sizeof(name));
    name[sizeof(name) - 1] = '\0';
    double width = pWidth(name, &L);
    decayBlock["width [GeV]"] = width;
    Json::Value branchings(Json::arrayValue); // Use array to hold branching information

    for (txtList curr = L; curr; curr = curr->next)
    {
        Json::Value branching(Json::objectValue);
        std::string branching_str(curr->txt);
        size_t split_pos = branching_str.find(" ");
        double branching_value = std::stod(branching_str.substr(0, split_pos));
        std::string decay_process = branching_str.substr(split_pos + 1);

        branching["value"] = branching_value;
        branching["mode"] = decay_process;
        branchings.append(branching);
    }

    decayBlock["branchings"] = branchings;
    return decayBlock;
}

int main(int argc, char **argv)
{
    int err;
    char cdmName[10];
    int spin2, charge3, cdim;

    Json::Value jsonData;
    Json::StreamWriterBuilder writer;
    std::ofstream jsonFile("output.json");

    ForceUG = 0; /* to Force Unitary Gauge assign 1 */
    VZdecay = 0;
    VWdecay = 0;

    if (argc == 1)
    {
        printf(" Correct usage:  ./main  <file with parameters> \n");
        printf("Example: ./main data1.par\n");
        exit(1);
    }

    err = readVar(argv[1]);

    if (err == -1)
    {
        printf("Can not open the file\n");
        exit(1);
    }
    else if (err > 0)
    {
        printf("Wrong file contents at line %d\n", err);
        exit(1);
    }

    err = sortOddParticles(cdmName);
    if (err)
    {
        printf("Can't calculate %s\n", cdmName);
        return 1;
    }

    for (int k = 1; k <= Ncdm; k++)
    {
        qNumbers(CDM[k], &spin2, &charge3, &cdim);
        printf("\nDark matter candidate is '%s' with spin=%d/2 mass=%.2E\n", CDM[k], spin2, McdmN[k]);
        if (charge3)
            printf("Dark Matter has electric charge %d/3\n", charge3);
        if (cdim != 1)
            printf("Dark Matter is a color particle\n");

        Json::Value candidate;
        candidate["name"] = CDM[k];
        candidate["spin"] = std::to_string(spin2) + "/2";
        candidate["mass [GeV]"] = McdmN[k];
        candidate["electric_charge"] = (charge3 != 0) ? std::to_string(charge3) + "/3" : "0";
        candidate["is_color_particle"] = (cdim != 1);
        jsonData["dark_matter_candidates"].append(candidate);
    }

#ifdef MASSES_INFO
    {
        printf("\n=== MASSES OF HIGGS AND ODD PARTICLES: ===\n");
        printHiggs(stdout);
        printMasses(stdout, 1);
        // jsonData["masses_info"]["Higgs_and_odd_particles"] = "Printed to console";
    }
#endif

#ifdef CONSTRAINTS
    {
        double csLim;
        if (Zinvisible())
        {
            printf("Excluded by Z->invizible\n");
            jsonData["constraints"]["Z_invisible"] = true;
        }
        if (LspNlsp_LEP(&csLim))
        {
            printf("LEP excluded by e+,e- -> DM q q-\bar  Cross Section= %.2E pb\n", csLim);
            jsonData["constraints"]["LEP_excluded"] = csLim;
        }
    }
#endif

#ifdef OMEGA
    {
        int fast = 0;
        double Beps = 1.E-4, cut = 0.000001;
        double Omega;
        int i, err;
        printf("\n==== Calculation of relic density =====\n");

        if (Ncdm == 1)
        {
            double Xf;
            Omega = darkOmega(&Xf, fast, Beps, &err);
            printf("Xf=%.2e Omega=%.2e\n", Xf, Omega);
            if (Omega > 0)
            {
                double Xf = 1.0; // Example arguments
                double cut = 1.e-8;
                double Beps = 0.0001;
                int prcn = 1;
                double result = printChannels(Xf, cut, Beps, prcn, stdout);

                double w = 1;
                int i = 0;
                while (w > 0)
                {
                    Json::Value inState;
                    inState.append(pNum(omegaCh[i].prtcl[0]));
                    inState.append(pNum(omegaCh[i].prtcl[1]));

                    Json::Value outState;
                    outState.append(pNum(omegaCh[i].prtcl[2]));
                    outState.append(pNum(omegaCh[i].prtcl[3]));
                    char buffer[256];
                    sprintf(buffer, "%s %s -> %s %s", omegaCh[i].prtcl[0], omegaCh[i].prtcl[1], omegaCh[i].prtcl[2], omegaCh[i].prtcl[3]);

                    jsonData["relic_density"]["Channels"][i]["inState"] = inState;
                    jsonData["relic_density"]["Channels"][i]["outState"] = outState;
                    jsonData["relic_density"]["Channels"][i]["weight"] = omegaCh[i].weight;
                    jsonData["relic_density"]["Channels"][i]["process"] = std::string(buffer);
                    i++;
                    w = omegaCh[i].weight;
                }
            }
            jsonData["relic_density"]["Omega"] = Omega;
            jsonData["relic_density"]["Xf"] = Xf;
        }
        else if (Ncdm == 2)
        {
            Omega = darkOmega2(fast, Beps, &err);
            printf("Omega_1h^2=%.2E Omega_2h^2=%.2E err=%d \n", Omega * fracCDM[1], Omega * fracCDM[2], err);
            jsonData["relic_density"]["Omega_1"] = Omega * fracCDM[1];
            jsonData["relic_density"]["Omega_2"] = Omega * fracCDM[2];
            jsonData["relic_density"]["error"] = err;
        }
        else
        {
            Omega = darkOmegaN(fast, Beps, &err);
            printf("Omega=%.2E\n", Omega);
            jsonData["relic_density"]["Omega"] = Omega;
            for (int k = 1; k <= Ncdm; k++)
            {
                printf("   Omega_%d=%.2E\n", k, Omega * fracCDM[k]);
                jsonData["relic_density"]["Omega_" + std::to_string(k)] = Omega * fracCDM[k];
            }
        }
    }
#endif

#ifdef INDIRECT_DETECTION
    {
        int err, i;
        double Emin = 1, sigmaV;
        double SpA[NZ], SpE[NZ], SpP[NZ];
        double FluxA[NZ], FluxE[NZ], FluxP[NZ];
        double *SpNe = NULL, *SpNm = NULL, *SpNl = NULL;
        double Etest = Mcdm / 2;

        printf("\n==== Indirect detection =======\n");

        sigmaV = calcSpectrum(1 + 2 + 4, SpA, SpE, SpP, SpNe, SpNm, SpNl, &err);
        jsonData["indirect_detection"]["sigmaV [cm^3/s]"] = sigmaV;

        double w = 1;
        int ii = 0;
        while (w > 0)
        {
            Json::Value inState;
            inState.append(pNum(vSigmaCh[ii].prtcl[0]));
            inState.append(pNum(vSigmaCh[ii].prtcl[1]));

            Json::Value outState;
            outState.append(pNum(vSigmaCh[ii].prtcl[2]));
            outState.append(pNum(vSigmaCh[ii].prtcl[3]));
            char buffer[256];
            sprintf(buffer, "%s %s -> %s %s", vSigmaCh[ii].prtcl[0], vSigmaCh[ii].prtcl[1], vSigmaCh[ii].prtcl[2], vSigmaCh[ii].prtcl[3]);

            jsonData["indirect_detection"]["Channels"][ii]["inState"] = inState;
            jsonData["indirect_detection"]["Channels"][ii]["outState"] = outState;
            jsonData["indirect_detection"]["Channels"][ii]["weight"] = vSigmaCh[ii].weight;
            jsonData["indirect_detection"]["Channels"][ii]["process"] = std::string(buffer);
            ii++;
            w = omegaCh[ii].weight;
        }

        {
            double fi = 0.1, dfi = 0.05; /* angle of sight and 1/2 of cone angle in [rad] */

            gammaFluxTab(fi, dfi, sigmaV, SpA, FluxA);
            printf("Photon flux  for angle of sight f=%.2f[rad]\n"
                   "and spherical region described by cone with angle %.2f[rad]\n",
                   fi, 2 * dfi);
            printf("Photon flux = %.2E[cm^2 s GeV]^{-1} for E=%.1f[GeV]\n", SpectdNdE(Etest, FluxA), Etest);
            jsonData["indirect_detection"]["photon_flux"]["value"] = SpectdNdE(Etest, FluxA);
            jsonData["indirect_detection"]["photon_flux"]["unit"] = "[cm^2 s GeV]^{-1}";
            jsonData["indirect_detection"]["photon_flux"]["E [GeV]"] = Etest;
        }

        {
            posiFluxTab(Emin, sigmaV, SpE, FluxE);
            printf("Positron flux  =  %.2E[cm^2 sr s GeV]^{-1} for E=%.1f[GeV] \n",
                   SpectdNdE(Etest, FluxE), Etest);
            jsonData["indirect_detection"]["positron_flux"]["value"] = SpectdNdE(Etest, FluxE);
            jsonData["indirect_detection"]["positron_flux"]["unit"] = "[cm^2 s GeV]^{-1}";
            jsonData["indirect_detection"]["positron_flux"]["E [GeV]"] = Etest;
        }

        {
            pbarFluxTab(Emin, sigmaV, SpP, FluxP);
            printf("Antiproton flux  =  %.2E[cm^2 sr s GeV]^{-1} for E=%.1f[GeV] \n",
                   SpectdNdE(Etest, FluxP), Etest);
            jsonData["indirect_detection"]["antiproton_flux"]["value"] = SpectdNdE(Etest, FluxP);
            jsonData["indirect_detection"]["antiproton_flux"]["unit"] = "[cm^2 s GeV]^{-1}";
            jsonData["indirect_detection"]["antiproton_flux"]["E [GeV]"] = Etest;
        }
    }
#endif

#ifdef CDM_NUCLEON
    {
        double pA0[2], pA5[2], nA0[2], nA5[2];
        double Nmass = 0.939; /*nucleon mass*/
        double SCcoeff;
        double csSIp1, csSIn1, csSDp1, csSDn1, csSIp1_, csSIn1_, csSDp1_, csSDn1_;
        printf("\n==== Calculation of CDM-nucleons amplitudes  =====\n");

        for (int k = 1; k <= Ncdm; k++)
        {
            nucleonAmplitudes(CDM[k], pA0, pA5, nA0, nA5);
            printf("%s[%s]-nucleon micrOMEGAs amplitudes\n", CDM[k], antiParticle(CDM[k]));
            printf("proton:  SI  %.3E [%.3E]  SD  %.3E [%.3E]\n", pA0[0], pA0[1], pA5[0], pA5[1]);
            printf("neutron: SI  %.3E [%.3E]  SD  %.3E [%.3E]\n", nA0[0], nA0[1], nA5[0], nA5[1]);

            Json::Value nucleon;
            nucleon["name"] = CDM[k];
            Json::Value proton_SI;
            proton_SI.append(pA0[0]);
            proton_SI.append(pA0[1]);
            nucleon["proton"]["SI"] = proton_SI;
            Json::Value proton_SD;
            proton_SD.append(pA5[0]);
            proton_SD.append(pA5[1]);
            nucleon["proton"]["SD"] = proton_SD;
            Json::Value neutron_SI;
            neutron_SI.append(nA0[0]);
            neutron_SI.append(nA0[1]);
            nucleon["neutron"]["SI"] = neutron_SI;
            Json::Value neutron_SD;
            neutron_SD.append(nA5[0]);
            neutron_SD.append(nA5[1]);
            nucleon["neutron"]["SD"] = neutron_SD;
            jsonData["cdm_nucleon_amplitudes"].append(nucleon);
        }
    }
#endif

#ifdef CDM_NUCLEUS
    {
        char *expName;
        printf("\n===== Direct detection exclusion:======\n");
        double pval = DD_pval(AllDDexp, Maxwell, &expName);
        if (pval < 0.1)
        {
            printf("Excluded by %s  %.1f%%\n", expName, 100 * (1 - pval));
            jsonData["direct_detection"]["excluded_by"] = expName;
            jsonData["direct_detection"]["exclusion_level"] = 100 * (1 - pval);
        }
        else
        {
            printf("Not excluded by DD experiments  at 90%% level \n");
            jsonData["direct_detection"]["excluded_by"] = "None";
            jsonData["direct_detection"]["exclusion_level"] = 0;
        }
    }
#endif

#ifdef DECAYS
    {
        char *pname = pdg2name(25);
        txtList L;
        double width;
        if (pname)
        {
            width = pWidth(pname, &L);
            printf("\n%s :   total width=%E \n and Branchings:\n", pname, width);
            printTxtList(L, stdout);
            jsonData["decays"][pname] = getDecayBlock(pname);
        }

        pname = pdg2name(24);
        if (pname)
        {
            width = pWidth(pname, &L);
            printf("\n%s :   total width=%E \n and Branchings:\n", pname, width);
            printTxtList(L, stdout);
            jsonData["decays"][pname] = getDecayBlock(pname);
        }
    }
#endif

#ifdef CLEAN
    system("rm -f HB.* HB.* hb.* hs.*  debug_channels.txt debug_predratio.txt  Key.dat");
    system("rm -f Lilith_*   particles.py*");
#endif

    jsonFile << Json::writeString(writer, jsonData);
    jsonFile.close();
    printf("\nData writen into -> output.json");

    killPlots();
    return 0;
}
