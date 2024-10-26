#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../CalcHEP_src/include/extern.h"
#include "../../CalcHEP_src/include/VandP.h"
#include "autoprot.h"
extern int  FError;
/*  Special model functions  */

int nModelParticles=51;
static ModelPrtclsStr ModelPrtcls_[51]=
{
  {"A","A",1, 22, "0","0",2,1,2,0}
, {"Z","Z",1, 23, "MZ","wZ",2,1,3,0}
, {"W+","W-",0, 24, "MW","wW",2,1,3,3}
, {"G","G",1, 21, "0","0",2,8,16,0}
, {"ne","Ne",0, 12, "0","0",1,1,1,0}
, {"e","E",0, 11, "0","0",1,1,2,-3}
, {"nm","Nm",0, 14, "0","0",1,1,1,0}
, {"m","M",0, 13, "0","0",1,1,2,-3}
, {"nl","Nl",0, 16, "0","0",1,1,1,0}
, {"l","L",0, 15, "Ml","0",1,1,2,-3}
, {"u","U",0, 2, "Mq","0",1,3,6,2}
, {"d","D",0, 1, "Mq","0",1,3,6,-1}
, {"s","S",0, 3, "Mq","0",1,3,6,-1}
, {"c","C",0, 4, "Mc","0",1,3,6,2}
, {"t","T",0, 6, "Mt","wt",1,3,6,2}
, {"b","B",0, 5, "Mb","0",1,3,6,-1}
, {"h1","h1",1, 25, "Mh1","wh1",0,1,1,0}
, {"h2","h2",1, 35, "Mh2","wh2",0,1,1,0}
, {"h3","h3",1, 45, "Mh3","wh3",0,1,1,0}
, {"ha","ha",1, 36, "Mha","wha",0,1,1,0}
, {"hb","hb",1, 46, "Mhb","whb",0,1,1,0}
, {"H+","H-",0, 37, "MHc","wHc",0,1,1,3}
, {"~1+","~1-",0, 1000024, "MC1","wC1",1,1,2,3}
, {"~2+","~2-",0, 1000037, "MC2","wC2",1,1,2,3}
, {"~o1","~o1",1, 1000022, "MNE1","0",1,1,2,0}
, {"~o2","~o2",1, 1000023, "MNE2","wNE2",1,1,2,0}
, {"~o3","~o3",1, 1000025, "MNE3","wNE3",1,1,2,0}
, {"~o4","~o4",1, 1000035, "MNE4","wNE4",1,1,2,0}
, {"~o5","~o5",1, 1000045, "MNE5","wNE5",1,1,2,0}
, {"~g","~g",1, 1000021, "MSG","wSG",1,8,16,0}
, {"~eL","~EL",0, 1000011, "MSeL","wSeL",0,1,1,-3}
, {"~eR","~ER",0, 2000011, "MSeR","wSeR",0,1,1,-3}
, {"~mL","~ML",0, 1000013, "MSmL","wSmL",0,1,1,-3}
, {"~mR","~MR",0, 2000013, "MSmR","wSmR",0,1,1,-3}
, {"~l1","~L1",0, 1000015, "MSl1","wSl1",0,1,1,-3}
, {"~l2","~L2",0, 2000015, "MSl2","wSl2",0,1,1,-3}
, {"~ne","~Ne",0, 1000012, "MSne","wSne",0,1,1,0}
, {"~nm","~Nm",0, 1000014, "MSnm","wSnm",0,1,1,0}
, {"~nl","~Nl",0, 1000016, "MSnl","wSnl",0,1,1,0}
, {"~uL","~UL",0, 1000002, "MSuL","wSuL",0,3,3,2}
, {"~uR","~UR",0, 2000002, "MSuR","wSuR",0,3,3,2}
, {"~dL","~DL",0, 1000001, "MSdL","wSdL",0,3,3,-1}
, {"~dR","~DR",0, 2000001, "MSdR","wSdR",0,3,3,-1}
, {"~cL","~CL",0, 1000004, "MScL","wScL",0,3,3,2}
, {"~cR","~CR",0, 2000004, "MScR","wScR",0,3,3,2}
, {"~sL","~SL",0, 1000003, "MSsL","wSsL",0,3,3,-1}
, {"~sR","~SR",0, 2000003, "MSsR","wSsR",0,3,3,-1}
, {"~t1","~T1",0, 1000006, "MSt1","wSt1",0,3,3,2}
, {"~t2","~T2",0, 2000006, "MSt2","wSt2",0,3,3,2}
, {"~b1","~B1",0, 1000005, "MSb1","wSb1",0,3,3,-1}
, {"~b2","~B2",0, 2000005, "MSb2","wSb2",0,3,3,-1}
};
ModelPrtclsStr *ModelPrtcls=ModelPrtcls_; 
int nModelVars=167;
int nModelFunc=219;
static int nCurrentVars=166;
int*currentVarPtr=&nCurrentVars;
static char*varNames_[386]={
 "Am","EE","MZ","MW","alfSMZ","MbMb","McMc","Mtp","Ml","Mq"
,"MG1","MG2","MG3","tb","tB","mu","xvev","Lambda","Kappa","aLambda"
,"aKappa","At","Ab","Al","muP","xif","xis","mXiF","mXiS","msP"
,"m3h","Ml2","Ml3","Mr2","Mr3","Mq2","Mq3","Mu2","Mu3","Md2"
,"Md3","Mh1","Mh2","Mh3","Mha","Mhb","MHc","MNE1","MNE2","MNE3"
,"MNE4","MNE5","MC1","MC2","MSG","MSuL","MSuR","MSdL","MSdR","MScL"
,"MScR","MSsL","MSsR","MSt1","MSt2","MSb1","MSb2","MSeL","MSeR","MSmL"
,"MSmR","MSl1","MSl2","MSne","MSnm","MSnl","Zn11","Zn12","Zn13","Zn14"
,"Zn15","Zn21","Zn22","Zn23","Zn24","Zn25","Zn31","Zn32","Zn33","Zn34"
,"Zn35","Zn41","Zn42","Zn43","Zn44","Zn45","Zn51","Zn52","Zn53","Zn54"
,"Zn55","Zu11","Zu12","Zu21","Zu22","Zv11","Zv12","Zv21","Zv22","Zt11"
,"Zt12","Zt21","Zt22","Zb11","Zb12","Zb21","Zb22","Zl11","Zl12","Zl21"
,"Zl22","Zh11","Zh12","Zh13","Zh21","Zh22","Zh23","Zh31","Zh32","Zh33"
,"Za11","Za12","Za13","Za21","Za22","Za23","la1","la2","la3","la4"
,"la5","la6","la7","la1s","la2s","la3s","la4s","la5s","la6s","la7s"
,"la8s","aa1","aa2","aa3","aa4","aa5","aa6","B1","B2","X"
,"dMb","MM3","MSP","Q","Au","Ad","Maux","CW","SW","vev"
,"C2W","LamQCD","sb","cb","t2b","Pa12","Pa22","Pa11","Pa21","Td3"
,"hMM11","hMM12","hMM13","hMM22","hMM23","hMM33","idS","Mh1_","Mh2_","Mh3_"
,"Zh11_","Zh12_","Zh13_","Zh21_","Zh22_","Zh23_","Zh31_","Zh32_","Zh33_","MA11"
,"MA12","MA22","idA","Pa11_","Pa12_","Pa21_","Pa22_","Mha_","Mhb_","Mt"
,"Mb","Mc","xH2","yH2","dMd","Td2","fiuu","fidd","ficc","fiss"
,"Zuu11","Zuu12","Zuu21","Zuu22","Zdd11","Zdd12","Zdd21","Zdd22","Zcc11","Zcc12"
,"Zcc21","Zcc22","Zss11","Zss12","Zss21","Zss22","MbMM","MtMM","NMM11","NMM12"
,"NMM13","NMM14","NMM15","NMM22","NMM23","NMM24","NMM25","NMM33","NMM34","NMM35"
,"NMM44","NMM45","NMM55","MG1I","MG2I","PI","Mbp","Mcp","ah1F_c","ah1F_b"
,"ah1F_t","ah1F_l","ah2F_c","ah2F_b","ah2F_t","ah2F_l","ah3F_c","ah3F_b","ah3F_t","ah3F_l"
,"ah1S_eL","ah1S_eR","ah1S_mL","ah1S_mR","ah1S_uL","ah1S_uR","ah1S_cL","ah1S_cR","ah1S_dL","ah1S_dR"
,"ah1S_sL","ah1S_sR","ah1S_l1","ah1S_l2","ah1S_t1","ah1S_t2","ah1S_b1","ah1S_b2","ah2S_eL","ah2S_eR"
,"ah2S_mL","ah2S_mR","ah2S_uL","ah2S_uR","ah2S_cL","ah2S_cR","ah2S_dL","ah2S_dR","ah2S_sL","ah2S_sR"
,"ah2S_l1","ah2S_l2","ah2S_t1","ah2S_t2","ah2S_b1","ah2S_b2","ah3S_eL","ah3S_eR","ah3S_mL","ah3S_mR"
,"ah3S_uL","ah3S_uR","ah3S_cL","ah3S_cR","ah3S_dL","ah3S_dR","ah3S_sL","ah3S_sR","ah3S_l1","ah3S_l2"
,"ah3S_t1","ah3S_t2","ah3S_b1","ah3S_b2","ah1V_W","B00000","B00001","B00002","B00003","B00004"
,"ah1S_Hc","ah2V_W","B00005","B00006","B00007","B00008","B00009","ah2S_Hc","ah3V_W","B00010"
,"B00011","B00012","B00013","B00014","ah3S_Hc","ah1F_c1","ah1F_c2","ah2F_c1","ah2F_c2","ah3F_c1"
,"ah3F_c2","ahaF_c","ahaF_b","ahaF_t","ahaF_l","ahbF_c","ahbF_b","ahbF_t","ahbF_l","ahaF_c1"
,"ahaF_c2","ahbF_c1","ahbF_c2","aQCDh1","Rqcdh1","aQCDh2","Rqcdh2","aQCDh3","Rqcdh3","aQCDha"
,"Rqcdha","aQCDhb","Rqcdhb","LGGh1","LGGh2","LGGh3","Quq","Qdq","LAAh1","LAAh2"
,"LAAh3","LGGha","LGGhb","LAAha","LAAhb","B00276"};
char**varNames=varNames_;
static REAL varValues_[386]={
   0.000000E+00,  3.122000E-01,  9.118700E+01,  8.037000E+01,  1.184000E-01,  4.180000E+00,  1.300000E+00,  1.730700E+02,  1.777000E+00,  5.000000E-02
,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00
,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00
,  0.000000E+00,  2.000000E+02,  2.000000E+02,  2.020000E+02,  2.000000E+02,  1.000000E+03,  1.000000E+03,  1.000000E+03,  1.000000E+03,  1.000000E+03
,  1.000000E+03,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00
,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00
,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00
,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00
,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00
,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00
,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00
,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00
,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00
,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00
,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00
,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00,  0.000000E+00
,  0.000000E+00,  0.000000E+00,  0.000000E+00,  1.000000E+02,  0.000000E+00,  0.000000E+00,  1.000000E+00};
REAL*varValues=varValues_;
int calcMainFunc(void)
{
   int i;
   static REAL * VV=NULL;
   static int iQ=-1;
   static int cErr=1;
   REAL *V=varValues;
   FError=0;
   if(VV && cErr==0)
   { for(i=0;i<nModelVars;i++) if(i!=iQ && VV[i]!=V[i]) break;
     if(i==nModelVars)      {if(iQ>=0 && VV[iQ]!=V[iQ]) goto FirstQ; else return 0;} 
   }
  cErr=1;
   nCurrentVars=167;
   V[167]=V[3]/(V[2]);
   if(!isfinite(V[167]) || FError) return 167;
   nCurrentVars=168;
   V[168]=Sqrt(1-Pow(V[167],2));
   if(!isfinite(V[168]) || FError) return 168;
   nCurrentVars=169;
   V[169]=M_SQRT2*V[3]*V[168]/(V[1]);
   if(!isfinite(V[169]) || FError) return 169;
   nCurrentVars=170;
   V[170]=Pow(V[167],2)-Pow(V[168],2);
   if(!isfinite(V[170]) || FError) return 170;
   nCurrentVars=171;
   V[171]=initQCD5(V[4],V[6],V[5],V[7]);
   if(!isfinite(V[171]) || FError) return 171;
   nCurrentVars=172;
   V[172]=V[14]/(Sqrt(1+Pow(V[14],2)));
   if(!isfinite(V[172]) || FError) return 172;
   nCurrentVars=173;
   V[173]=Sqrt(1-Pow(V[172],2));
   if(!isfinite(V[173]) || FError) return 173;
   nCurrentVars=174;
   V[174]=2*V[14]/(1-Pow(V[14],2));
   if(!isfinite(V[174]) || FError) return 174;
   nCurrentVars=175;
   V[175]=V[132];

   nCurrentVars=176;
   V[176]=V[135];

   nCurrentVars=177;
   V[177]=(V[130]*V[176]>0 ? V[176] : -V[176]);
   if(!isfinite(V[177]) || FError) return 177;
   nCurrentVars=178;
   V[178]=(V[133]*V[175]>0 ? V[175] : -V[175]);
   if(!isfinite(V[178]) || FError) return 178;
   nCurrentVars=179;
   V[179]=V[160]/(1+V[160]);
   if(!isfinite(V[179]) || FError) return 179;
   nCurrentVars=180;
   V[180]=4/(Pow(V[1],2))*Pow(V[3],2)*Pow(V[168],2)*V[173]*V[173]*V[136]-6/(Pow(V[1],2))*Pow(V[3],2)*Pow(V[168],2)*V[173]*V[141]*V[172]+1*V[157]/(V[173])*V[172]+1*V[155]/(V[173])*V[172]*V[16]+1*V[156]/(V[173])*V[172]*V[16]+1/(V[173])*V[146]*V[172]*Pow(V[16],2)+1/(V[173])*V[147]*V[172]*Pow(V[16],2)+1/(V[173])*V[148]*V[172]*Pow(V[16],2)+2/(Pow(V[1],2))*Pow(V[3],2)*Pow(V[168],2)/(V[173])*V[142]*Pow(V[172],3);
   if(!isfinite(V[180]) || FError) return 180;
   nCurrentVars=181;
   V[181]=4/(Pow(V[1],2))*Pow(V[3],2)*Pow(V[168],2)*V[173]*V[138]*V[172]+4/(Pow(V[1],2))*Pow(V[3],2)*Pow(V[168],2)*V[173]*V[139]*V[172]+4/(Pow(V[1],2))*Pow(V[3],2)*Pow(V[168],2)*V[173]*V[140]*V[172]-6/(Pow(V[1],2))*Pow(V[3],2)*Pow(V[168],2)*V[173]*V[173]*V[141]-6/(Pow(V[1],2))*Pow(V[3],2)*Pow(V[168],2)*V[142]*Pow(V[172],2)-1*V[146]*Pow(V[16],2)-1*V[147]*Pow(V[16],2)-1*V[148]*Pow(V[16],2)-1*V[155]*V[16]-1*V[156]*V[16]-1*V[157];
   if(!isfinite(V[181]) || FError) return 181;
   nCurrentVars=182;
   V[182]=2/(V[1])*V[3]*V[168]*M_SQRT2*V[173]*V[143]*V[16]-2/(V[1])*V[3]*V[168]*M_SQRT2*V[146]*V[172]*V[16]-2/(V[1])*V[3]*V[168]*M_SQRT2*V[147]*V[172]*V[16]-2/(V[1])*V[3]*V[168]*M_SQRT2*V[148]*V[172]*V[16]+2/(V[1])*V[3]*V[168]*M_SQRT2*V[151]*V[173]-1/(V[1])*V[3]*V[168]*M_SQRT2*V[155]*V[172]-1/(V[1])*V[3]*V[168]*M_SQRT2*V[156]*V[172];
   if(!isfinite(V[182]) || FError) return 182;
   nCurrentVars=183;
   V[183]=4/(Pow(V[1],2))*Pow(V[3],2)*Pow(V[168],2)*V[137]*Pow(V[172],2)-6/(Pow(V[1],2))*Pow(V[3],2)*Pow(V[168],2)*V[173]*V[142]*V[172]+1*V[157]*V[173]/(V[172])+1*V[155]*V[173]/(V[172])*V[16]+1*V[156]*V[173]/(V[172])*V[16]+2/(Pow(V[1],2))*Pow(V[3],2)*Pow(V[168],2)*Pow(V[173],3)*V[141]/(V[172])+1*V[173]*V[146]/(V[172])*Pow(V[16],2)+1*V[173]*V[147]/(V[172])*Pow(V[16],2)+1*V[173]*V[148]/(V[172])*Pow(V[16],2);
   if(!isfinite(V[183]) || FError) return 183;
   nCurrentVars=184;
   V[184]=2/(V[1])*V[3]*V[168]*M_SQRT2*V[144]*V[172]*V[16]-2/(V[1])*V[3]*V[168]*M_SQRT2*V[173]*V[146]*V[16]-2/(V[1])*V[3]*V[168]*M_SQRT2*V[173]*V[147]*V[16]-2/(V[1])*V[3]*V[168]*M_SQRT2*V[173]*V[148]*V[16]+2/(V[1])*V[3]*V[168]*M_SQRT2*V[152]*V[172]-1/(V[1])*V[3]*V[168]*M_SQRT2*V[155]*V[173]-1/(V[1])*V[3]*V[168]*M_SQRT2*V[156]*V[173];
   if(!isfinite(V[184]) || FError) return 184;
   nCurrentVars=185;
   V[185]=4*V[145]*Pow(V[16],2)+8*V[149]*Pow(V[16],2)+8*V[150]*Pow(V[16],2)+3*V[153]*V[16]+3*V[154]*V[16]-1*V[159]/(V[16])-2/(Pow(V[1],2))*Pow(V[3],2)*Pow(V[168],2)*V[151]*V[173]*V[173]/(V[16])-2/(Pow(V[1],2))*Pow(V[3],2)*Pow(V[168],2)*V[152]*Pow(V[172],2)/(V[16])+2/(Pow(V[1],2))*Pow(V[3],2)*Pow(V[168],2)*V[155]*V[173]*V[172]/(V[16])+2/(Pow(V[1],2))*Pow(V[3],2)*Pow(V[168],2)*V[156]*V[173]*V[172]/(V[16]);
   if(!isfinite(V[185]) || FError) return 185;
   nCurrentVars=186;
   V[186]=rDiagonal(3,V[180],V[181],V[182],V[183],V[184],V[185]);
   if(!isfinite(V[186]) || FError) return 186;
   nCurrentVars=187;
   V[187]=MassArray(V[186],1)/(Sqrt(Fabs(MassArray(V[186],1))));
   if(!isfinite(V[187]) || FError) return 187;
   nCurrentVars=188;
   V[188]=MassArray(V[186],2)/(Sqrt(Fabs(MassArray(V[186],2))));
   if(!isfinite(V[188]) || FError) return 188;
   nCurrentVars=189;
   V[189]=MassArray(V[186],3)/(Sqrt(Fabs(MassArray(V[186],3))));
   if(!isfinite(V[189]) || FError) return 189;
   nCurrentVars=190;
   V[190]=MixMatrix(V[186],1,1);
   if(!isfinite(V[190]) || FError) return 190;
   nCurrentVars=191;
   V[191]=MixMatrix(V[186],1,2);
   if(!isfinite(V[191]) || FError) return 191;
   nCurrentVars=192;
   V[192]=MixMatrix(V[186],1,3);
   if(!isfinite(V[192]) || FError) return 192;
   nCurrentVars=193;
   V[193]=MixMatrix(V[186],2,1);
   if(!isfinite(V[193]) || FError) return 193;
   nCurrentVars=194;
   V[194]=MixMatrix(V[186],2,2);
   if(!isfinite(V[194]) || FError) return 194;
   nCurrentVars=195;
   V[195]=MixMatrix(V[186],2,3);
   if(!isfinite(V[195]) || FError) return 195;
   nCurrentVars=196;
   V[196]=MixMatrix(V[186],3,1);
   if(!isfinite(V[196]) || FError) return 196;
   nCurrentVars=197;
   V[197]=MixMatrix(V[186],3,2);
   if(!isfinite(V[197]) || FError) return 197;
   nCurrentVars=198;
   V[198]=MixMatrix(V[186],3,3);
   if(!isfinite(V[198]) || FError) return 198;
   nCurrentVars=199;
   V[199]=2/(Pow(V[1],2))*Pow(V[3],2)*Pow(V[168],2)*V[173]*V[141]/(V[172])-4/(Pow(V[1],2))*Pow(V[3],2)*Pow(V[168],2)*V[140]+2/(Pow(V[1],2))*Pow(V[3],2)*Pow(V[168],2)/(V[173])*V[142]*V[172]+1*V[157]/(V[173])/(V[172])+1*V[155]/(V[173])/(V[172])*V[16]+1*V[156]/(V[173])/(V[172])*V[16]+1/(V[173])*V[146]/(V[172])*Pow(V[16],2)+1/(V[173])*V[147]/(V[172])*Pow(V[16],2)+1/(V[173])*V[148]/(V[172])*Pow(V[16],2);
   if(!isfinite(V[199]) || FError) return 199;
   nCurrentVars=200;
   V[200]=(2*V[147]*V[16]-2*V[148]*V[16]+V[155]-V[156])*V[3]*V[168]*M_SQRT2/(V[1]);
   if(!isfinite(V[200]) || FError) return 200;
   nCurrentVars=201;
   V[201]=(4*V[173]*V[147]*V[172]+4*V[173]*V[148]*V[172]+(V[155]*V[173]*V[172]-V[152]*Pow(V[172],2)-V[151]*V[173]*V[173]+V[156]*V[173]*V[172])/(V[16]))*2/(Pow(V[1],2))*Pow(V[3],2)*Pow(V[168],2)-16*V[149]*Pow(V[16],2)-1*V[153]*V[16]-9*V[154]*V[16]-4*V[158]-1*V[159]/(V[16])-4*V[150]*Pow(V[16],2);
   if(!isfinite(V[201]) || FError) return 201;
   nCurrentVars=202;
   V[202]=rDiagonal(2,V[199],V[200],V[201]);
   if(!isfinite(V[202]) || FError) return 202;
   nCurrentVars=203;
   V[203]=MixMatrix(V[202],1,1);
   if(!isfinite(V[203]) || FError) return 203;
   nCurrentVars=204;
   V[204]=MixMatrix(V[202],1,2);
   if(!isfinite(V[204]) || FError) return 204;
   nCurrentVars=205;
   V[205]=MixMatrix(V[202],2,1);
   if(!isfinite(V[205]) || FError) return 205;
   nCurrentVars=206;
   V[206]=MixMatrix(V[202],2,2);
   if(!isfinite(V[206]) || FError) return 206;
   nCurrentVars=207;
   V[207]=MassArray(V[202],1)/(Sqrt(Fabs(MassArray(V[202],1))));
   if(!isfinite(V[207]) || FError) return 207;
   nCurrentVars=208;
   V[208]=MassArray(V[202],2)/(Sqrt(Fabs(MassArray(V[202],2))));
   if(!isfinite(V[208]) || FError) return 208;
 FirstQ:
 cErr=1;
   nCurrentVars=209;
   V[209]=MtEff(V[163]);
   if(!isfinite(V[209]) || FError) return 209;
   nCurrentVars=210;
   V[210]=MbEff(V[163]);
   if(!isfinite(V[210]) || FError) return 210;
   nCurrentVars=211;
   V[211]=McEff(V[163]);
   if(!isfinite(V[211]) || FError) return 211;
   nCurrentVars=212;
   V[212]=Pow(V[61],2)/(Pow(V[54],2));
   if(!isfinite(V[212]) || FError) return 212;
   nCurrentVars=213;
   V[213]=Pow(V[62],2)/(Pow(V[54],2));
   if(!isfinite(V[213]) || FError) return 213;
   nCurrentVars=214;
   V[214]=-3/(double)((2))*alphaQCD(V[54])/(3.1415)*V[14]*V[15]/(V[54])*(V[212]*Log(V[212])/(1-V[212])-V[213]*Log(V[213])/(1-V[213]))/(V[212]-V[213]);
   if(!isfinite(V[214]) || FError) return 214;
   nCurrentVars=215;
   V[215]=V[214]/(1+V[214]);
   if(!isfinite(V[215]) || FError) return 215;
   nCurrentVars=216;
   V[216]=Atan(-2*V[9]*(V[164]-V[15]/(V[14]))/(Pow(V[56],2)-Pow(V[55],2)))/(2);
   if(!isfinite(V[216]) || FError) return 216;
   nCurrentVars=217;
   V[217]=Atan(-2*V[9]*(1-V[215])*(V[165]-V[15]*V[14])/(Pow(V[58],2)-Pow(V[57],2)))/(2);
   if(!isfinite(V[217]) || FError) return 217;
   nCurrentVars=218;
   V[218]=Atan(-2*V[211]*(V[164]-V[15]/(V[14]))/(Pow(V[60],2)-Pow(V[59],2)))/(2);
   if(!isfinite(V[218]) || FError) return 218;
   nCurrentVars=219;
   V[219]=Atan(-2*V[9]*(1-V[215])*(V[165]-V[15]*V[14])/(Pow(V[62],2)-Pow(V[61],2)))/(2);
   if(!isfinite(V[219]) || FError) return 219;
   nCurrentVars=220;
   V[220]=Cos(V[216]);
   if(!isfinite(V[220]) || FError) return 220;
   nCurrentVars=221;
   V[221]=Sin(V[216]);
   if(!isfinite(V[221]) || FError) return 221;
   nCurrentVars=222;
   V[222]=-Sin(V[216]);
   if(!isfinite(V[222]) || FError) return 222;
   nCurrentVars=223;
   V[223]=Cos(V[216]);
   if(!isfinite(V[223]) || FError) return 223;
   nCurrentVars=224;
   V[224]=Cos(V[217]);
   if(!isfinite(V[224]) || FError) return 224;
   nCurrentVars=225;
   V[225]=Sin(V[217]);
   if(!isfinite(V[225]) || FError) return 225;
   nCurrentVars=226;
   V[226]=-Sin(V[217]);
   if(!isfinite(V[226]) || FError) return 226;
   nCurrentVars=227;
   V[227]=Cos(V[217]);
   if(!isfinite(V[227]) || FError) return 227;
   nCurrentVars=228;
   V[228]=Cos(V[218]);
   if(!isfinite(V[228]) || FError) return 228;
   nCurrentVars=229;
   V[229]=Sin(V[218]);
   if(!isfinite(V[229]) || FError) return 229;
   nCurrentVars=230;
   V[230]=-Sin(V[218]);
   if(!isfinite(V[230]) || FError) return 230;
   nCurrentVars=231;
   V[231]=Cos(V[218]);
   if(!isfinite(V[231]) || FError) return 231;
   nCurrentVars=232;
   V[232]=Cos(V[219]);
   if(!isfinite(V[232]) || FError) return 232;
   nCurrentVars=233;
   V[233]=Sin(V[219]);
   if(!isfinite(V[233]) || FError) return 233;
   nCurrentVars=234;
   V[234]=-Sin(V[219]);
   if(!isfinite(V[234]) || FError) return 234;
   nCurrentVars=235;
   V[235]=Cos(V[219]);
   if(!isfinite(V[235]) || FError) return 235;
   nCurrentVars=236;
   V[236]=MbRun(Sqrt(V[65]*V[66]));
   if(!isfinite(V[236]) || FError) return 236;
   nCurrentVars=237;
   V[237]=MtRun(Sqrt(V[63]*V[64]));
   if(!isfinite(V[237]) || FError) return 237;
   nCurrentVars=238;
   V[238]=V[76]*V[47]*V[76]+V[81]*V[48]*V[81]+V[86]*V[49]*V[86]+V[91]*V[50]*V[91]+V[96]*V[51]*V[96];
   if(!isfinite(V[238]) || FError) return 238;
   nCurrentVars=239;
   V[239]=V[76]*V[47]*V[77]+V[81]*V[48]*V[82]+V[86]*V[49]*V[87]+V[91]*V[50]*V[92]+V[96]*V[51]*V[97];
   if(!isfinite(V[239]) || FError) return 239;
   nCurrentVars=240;
   V[240]=V[76]*V[47]*V[78]+V[81]*V[48]*V[83]+V[86]*V[49]*V[88]+V[91]*V[50]*V[93]+V[96]*V[51]*V[98];
   if(!isfinite(V[240]) || FError) return 240;
   nCurrentVars=241;
   V[241]=V[76]*V[47]*V[79]+V[81]*V[48]*V[84]+V[86]*V[49]*V[89]+V[91]*V[50]*V[94]+V[96]*V[51]*V[99];
   if(!isfinite(V[241]) || FError) return 241;
   nCurrentVars=242;
   V[242]=V[76]*V[47]*V[80]+V[81]*V[48]*V[85]+V[86]*V[49]*V[90]+V[91]*V[50]*V[95]+V[96]*V[51]*V[100];
   if(!isfinite(V[242]) || FError) return 242;
   nCurrentVars=243;
   V[243]=V[77]*V[47]*V[77]+V[82]*V[48]*V[82]+V[87]*V[49]*V[87]+V[92]*V[50]*V[92]+V[97]*V[51]*V[97];
   if(!isfinite(V[243]) || FError) return 243;
   nCurrentVars=244;
   V[244]=V[77]*V[47]*V[78]+V[82]*V[48]*V[83]+V[87]*V[49]*V[88]+V[92]*V[50]*V[93]+V[97]*V[51]*V[98];
   if(!isfinite(V[244]) || FError) return 244;
   nCurrentVars=245;
   V[245]=V[77]*V[47]*V[79]+V[82]*V[48]*V[84]+V[87]*V[49]*V[89]+V[92]*V[50]*V[94]+V[97]*V[51]*V[99];
   if(!isfinite(V[245]) || FError) return 245;
   nCurrentVars=246;
   V[246]=V[77]*V[47]*V[80]+V[82]*V[48]*V[85]+V[87]*V[49]*V[90]+V[92]*V[50]*V[95]+V[97]*V[51]*V[100];
   if(!isfinite(V[246]) || FError) return 246;
   nCurrentVars=247;
   V[247]=V[78]*V[47]*V[78]+V[83]*V[48]*V[83]+V[88]*V[49]*V[88]+V[93]*V[50]*V[93]+V[98]*V[51]*V[98];
   if(!isfinite(V[247]) || FError) return 247;
   nCurrentVars=248;
   V[248]=V[78]*V[47]*V[79]+V[83]*V[48]*V[84]+V[88]*V[49]*V[89]+V[93]*V[50]*V[94]+V[98]*V[51]*V[99];
   if(!isfinite(V[248]) || FError) return 248;
   nCurrentVars=249;
   V[249]=V[78]*V[47]*V[80]+V[83]*V[48]*V[85]+V[88]*V[49]*V[90]+V[93]*V[50]*V[95]+V[98]*V[51]*V[100];
   if(!isfinite(V[249]) || FError) return 249;
   nCurrentVars=250;
   V[250]=V[79]*V[47]*V[79]+V[84]*V[48]*V[84]+V[89]*V[49]*V[89]+V[94]*V[50]*V[94]+V[99]*V[51]*V[99];
   if(!isfinite(V[250]) || FError) return 250;
   nCurrentVars=251;
   V[251]=V[79]*V[47]*V[80]+V[84]*V[48]*V[85]+V[89]*V[49]*V[90]+V[94]*V[50]*V[95]+V[99]*V[51]*V[100];
   if(!isfinite(V[251]) || FError) return 251;
   nCurrentVars=252;
   V[252]=V[80]*V[47]*V[80]+V[85]*V[48]*V[85]+V[90]*V[49]*V[90]+V[95]*V[50]*V[95]+V[100]*V[51]*V[100];
   if(!isfinite(V[252]) || FError) return 252;
   nCurrentVars=253;
   V[253]=V[238];

   nCurrentVars=254;
   V[254]=V[243];

   nCurrentVars=255;
   V[255]=4*Atan(1);
   if(!isfinite(V[255]) || FError) return 255;
   nCurrentVars=256;
   V[256]=V[5]*(1+4/(double)((3))*alphaQCD(V[5])/(V[255]));
   if(!isfinite(V[256]) || FError) return 256;
   nCurrentVars=257;
   V[257]=V[6]*(1+4/(double)((3))*alphaQCD(V[6])/(V[255]));
   if(!isfinite(V[257]) || FError) return 257;
   nCurrentVars=258;
   V[258]=-V[1]/(V[3])*V[211]/(V[168])*V[122]/(V[172])/(2)/(V[211]);
   if(!isfinite(V[258]) || FError) return 258;
   nCurrentVars=259;
   V[259]=-V[1]/(V[3])*V[210]/(V[168])/(V[173])/(V[172])*(V[172]*V[121]-V[172]*V[179]*V[121]+V[179]*V[122]*V[173])/(2)/(V[210]);
   if(!isfinite(V[259]) || FError) return 259;
   nCurrentVars=260;
   V[260]=-V[1]/(V[3])*V[209]/(V[168])*V[122]/(V[172])/(2)/(V[209]);
   if(!isfinite(V[260]) || FError) return 260;
   nCurrentVars=261;
   V[261]=-V[1]/(V[3])*V[8]/(V[168])*V[121]/(V[173])/(2)/(V[8]);
   if(!isfinite(V[261]) || FError) return 261;
   nCurrentVars=262;
   V[262]=-V[1]/(V[3])*V[211]/(V[168])*V[125]/(V[172])/(2)/(V[211]);
   if(!isfinite(V[262]) || FError) return 262;
   nCurrentVars=263;
   V[263]=-V[1]/(V[3])*V[210]/(V[168])/(V[173])/(V[172])*(V[172]*V[124]-V[172]*V[179]*V[124]+V[179]*V[125]*V[173])/(2)/(V[210]);
   if(!isfinite(V[263]) || FError) return 263;
   nCurrentVars=264;
   V[264]=-V[1]/(V[3])*V[209]/(V[168])*V[125]/(V[172])/(2)/(V[209]);
   if(!isfinite(V[264]) || FError) return 264;
   nCurrentVars=265;
   V[265]=-V[1]/(V[3])*V[8]/(V[168])*V[124]/(V[173])/(2)/(V[8]);
   if(!isfinite(V[265]) || FError) return 265;
   nCurrentVars=266;
   V[266]=-V[1]/(V[3])*V[211]/(V[168])*V[128]/(V[172])/(2)/(V[211]);
   if(!isfinite(V[266]) || FError) return 266;
   nCurrentVars=267;
   V[267]=-V[1]/(V[3])*V[210]/(V[168])/(V[173])/(V[172])*(V[172]*V[127]-V[172]*V[179]*V[127]+V[179]*V[128]*V[173])/(2)/(V[210]);
   if(!isfinite(V[267]) || FError) return 267;
   nCurrentVars=268;
   V[268]=-V[1]/(V[3])*V[209]/(V[168])*V[128]/(V[172])/(2)/(V[209]);
   if(!isfinite(V[268]) || FError) return 268;
   nCurrentVars=269;
   V[269]=-V[1]/(V[3])*V[8]/(V[168])*V[127]/(V[173])/(2)/(V[8]);
   if(!isfinite(V[269]) || FError) return 269;
   nCurrentVars=270;
   V[270]=V[170]/(Pow(V[167],2))*V[1]*V[3]/(V[168])*(V[121]*V[173]-V[172]*V[122])/(2)/(Pow(V[67],2));
   if(!isfinite(V[270]) || FError) return 270;
   nCurrentVars=271;
   V[271]=1/(Pow(V[167],2))*V[1]*V[3]*V[168]*(V[121]*V[173]-V[172]*V[122])/(Pow(V[68],2));
   if(!isfinite(V[271]) || FError) return 271;
   nCurrentVars=272;
   V[272]=V[170]/(Pow(V[167],2))*V[1]*V[3]/(V[168])*(V[121]*V[173]-V[172]*V[122])/(2)/(Pow(V[69],2));
   if(!isfinite(V[272]) || FError) return 272;
   nCurrentVars=273;
   V[273]=1/(Pow(V[167],2))*V[1]*V[3]*V[168]*(V[121]*V[173]-V[172]*V[122])/(Pow(V[70],2));
   if(!isfinite(V[273]) || FError) return 273;
   nCurrentVars=274;
   V[274]=1/(Pow(V[167],2))/(V[3])/(V[168])/(V[172])*(4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[121]*Pow(V[220],2)*V[173]-3*V[172]*V[1]*Pow(V[3],2)*V[121]*Pow(V[220],2)*V[173]-4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[122]*Pow(V[220],2)+3*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[122]*Pow(V[220],2)-4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[121]*Pow(V[221],2)*V[173]+4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[122]*Pow(V[221],2)+6*Pow(V[167],2)*V[1]*V[17]*V[9]*V[121]*V[220]*V[221]*V[16]+6*Pow(V[167],2)*V[168]*V[17]*V[3]*V[9]*M_SQRT2*V[123]*V[220]*V[221]*V[173]-6*Pow(V[167],2)*V[164]*V[1]*V[9]*V[122]*V[220]*V[221]-6*Pow(V[167],2)*V[1]*Pow(V[9],2)*V[122])/(6)/(Pow(V[55],2));
   if(!isfinite(V[274]) || FError) return 274;
   nCurrentVars=275;
   V[275]=1/(Pow(V[167],2))/(V[3])/(V[168])/(V[172])*(4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[121]*Pow(V[222],2)*V[173]-3*V[172]*V[1]*Pow(V[3],2)*V[121]*Pow(V[222],2)*V[173]-4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[122]*Pow(V[222],2)+3*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[122]*Pow(V[222],2)-4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[121]*Pow(V[223],2)*V[173]+4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[122]*Pow(V[223],2)+6*Pow(V[167],2)*V[1]*V[17]*V[9]*V[121]*V[222]*V[223]*V[16]+6*Pow(V[167],2)*V[168]*V[17]*V[3]*V[9]*M_SQRT2*V[123]*V[222]*V[223]*V[173]-6*Pow(V[167],2)*V[164]*V[1]*V[9]*V[122]*V[222]*V[223]-6*Pow(V[167],2)*V[1]*Pow(V[9],2)*V[122])/(6)/(Pow(V[56],2));
   if(!isfinite(V[275]) || FError) return 275;
   nCurrentVars=276;
   V[276]=1/(Pow(V[167],2))/(V[3])/(V[168])/(V[172])*(4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[228],2)*V[121]*V[173]-3*V[172]*V[1]*Pow(V[3],2)*Pow(V[228],2)*V[121]*V[173]-4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*Pow(V[228],2)*V[122]+3*Pow(V[172],2)*V[1]*Pow(V[3],2)*Pow(V[228],2)*V[122]-4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[229],2)*V[121]*V[173]+4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*Pow(V[229],2)*V[122]+6*Pow(V[167],2)*V[1]*V[17]*V[211]*V[228]*V[229]*V[121]*V[16]+6*Pow(V[167],2)*V[168]*V[17]*V[3]*V[211]*M_SQRT2*V[228]*V[229]*V[123]*V[173]-6*Pow(V[167],2)*V[164]*V[1]*V[211]*V[228]*V[229]*V[122]-6*Pow(V[167],2)*V[1]*Pow(V[211],2)*V[122])/(6)/(Pow(V[59],2));
   if(!isfinite(V[276]) || FError) return 276;
   nCurrentVars=277;
   V[277]=1/(Pow(V[167],2))/(V[3])/(V[168])/(V[172])*(4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[230],2)*V[121]*V[173]-3*V[172]*V[1]*Pow(V[3],2)*Pow(V[230],2)*V[121]*V[173]-4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*Pow(V[230],2)*V[122]+3*Pow(V[172],2)*V[1]*Pow(V[3],2)*Pow(V[230],2)*V[122]-4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[231],2)*V[121]*V[173]+4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*Pow(V[231],2)*V[122]+6*Pow(V[167],2)*V[1]*V[17]*V[211]*V[230]*V[231]*V[121]*V[16]+6*Pow(V[167],2)*V[168]*V[17]*V[3]*V[211]*M_SQRT2*V[230]*V[231]*V[123]*V[173]-6*Pow(V[167],2)*V[164]*V[1]*V[211]*V[230]*V[231]*V[122]-6*Pow(V[167],2)*V[1]*Pow(V[211],2)*V[122])/(6)/(Pow(V[60],2));
   if(!isfinite(V[277]) || FError) return 277;
   nCurrentVars=278;
   V[278]=-1/(Pow(V[167],2))/(V[3])/(V[168])/(V[173])*(2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[224],2)*V[121]-3*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[224],2)*V[121]-2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[224],2)*V[122]*V[173]+3*V[172]*V[1]*Pow(V[3],2)*Pow(V[224],2)*V[122]*V[173]-2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[225],2)*V[121]+2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[225],2)*V[122]*V[173]-6*Pow(V[167],2)*V[1]*V[17]*V[9]*V[224]*V[225]*V[122]*V[16]-6*Pow(V[167],2)*V[168]*V[172]*V[17]*V[3]*V[9]*M_SQRT2*V[224]*V[225]*V[123]+6*Pow(V[167],2)*V[165]*V[1]*V[9]*V[224]*V[225]*V[121]+6*Pow(V[167],2)*V[1]*Pow(V[9],2)*V[121])/(6)/(Pow(V[57],2));
   if(!isfinite(V[278]) || FError) return 278;
   nCurrentVars=279;
   V[279]=-1/(Pow(V[167],2))/(V[3])/(V[168])/(V[173])*(2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[226],2)*V[121]-3*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[226],2)*V[121]-2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[226],2)*V[122]*V[173]+3*V[172]*V[1]*Pow(V[3],2)*Pow(V[226],2)*V[122]*V[173]-2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[227],2)*V[121]+2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[227],2)*V[122]*V[173]-6*Pow(V[167],2)*V[1]*V[17]*V[9]*V[226]*V[227]*V[122]*V[16]-6*Pow(V[167],2)*V[168]*V[172]*V[17]*V[3]*V[9]*M_SQRT2*V[226]*V[227]*V[123]+6*Pow(V[167],2)*V[165]*V[1]*V[9]*V[226]*V[227]*V[121]+6*Pow(V[167],2)*V[1]*Pow(V[9],2)*V[121])/(6)/(Pow(V[58],2));
   if(!isfinite(V[279]) || FError) return 279;
   nCurrentVars=280;
   V[280]=-1/(Pow(V[167],2))/(V[3])/(V[168])/(V[173])*(2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*V[121]*Pow(V[232],2)-3*Pow(V[173],2)*V[1]*Pow(V[3],2)*V[121]*Pow(V[232],2)-2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[122]*Pow(V[232],2)*V[173]+3*V[172]*V[1]*Pow(V[3],2)*V[122]*Pow(V[232],2)*V[173]-2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*V[121]*Pow(V[233],2)+2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[122]*Pow(V[233],2)*V[173]-6*Pow(V[167],2)*V[1]*V[17]*V[9]*V[122]*V[232]*V[233]*V[16]-6*Pow(V[167],2)*V[168]*V[172]*V[17]*V[3]*V[9]*M_SQRT2*V[123]*V[232]*V[233]+6*Pow(V[167],2)*V[165]*V[1]*V[9]*V[121]*V[232]*V[233]+6*Pow(V[167],2)*V[1]*Pow(V[9],2)*V[121])/(6)/(Pow(V[61],2));
   if(!isfinite(V[280]) || FError) return 280;
   nCurrentVars=281;
   V[281]=-1/(Pow(V[167],2))/(V[3])/(V[168])/(V[173])*(2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*V[121]*Pow(V[234],2)-3*Pow(V[173],2)*V[1]*Pow(V[3],2)*V[121]*Pow(V[234],2)-2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[122]*Pow(V[234],2)*V[173]+3*V[172]*V[1]*Pow(V[3],2)*V[122]*Pow(V[234],2)*V[173]-2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*V[121]*Pow(V[235],2)+2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[122]*Pow(V[235],2)*V[173]-6*Pow(V[167],2)*V[1]*V[17]*V[9]*V[122]*V[234]*V[235]*V[16]-6*Pow(V[167],2)*V[168]*V[172]*V[17]*V[3]*V[9]*M_SQRT2*V[123]*V[234]*V[235]+6*Pow(V[167],2)*V[165]*V[1]*V[9]*V[121]*V[234]*V[235]+6*Pow(V[167],2)*V[1]*Pow(V[9],2)*V[121])/(6)/(Pow(V[62],2));
   if(!isfinite(V[281]) || FError) return 281;
   nCurrentVars=282;
   V[282]=1/(Pow(V[167],2))/(V[3])/(V[168])/(V[173])*(Pow(V[173],2)*V[170]*V[1]*Pow(V[3],2)*V[121]*Pow(V[117],2)-V[172]*V[170]*V[1]*Pow(V[3],2)*V[122]*Pow(V[117],2)*V[173]+2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*V[121]*Pow(V[118],2)-2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[122]*Pow(V[118],2)*V[173]+2*Pow(V[167],2)*V[1]*V[17]*V[8]*V[122]*V[117]*V[118]*V[16]+2*Pow(V[167],2)*V[168]*V[172]*V[17]*V[3]*V[8]*M_SQRT2*V[123]*V[117]*V[118]-2*Pow(V[167],2)*V[23]*V[1]*V[8]*V[121]*V[117]*V[118]-2*Pow(V[167],2)*V[1]*Pow(V[8],2)*V[121])/(2)/(Pow(V[71],2));
   if(!isfinite(V[282]) || FError) return 282;
   nCurrentVars=283;
   V[283]=1/(Pow(V[167],2))/(V[3])/(V[168])/(V[173])*(Pow(V[173],2)*V[170]*V[1]*Pow(V[3],2)*V[121]*Pow(V[119],2)-V[172]*V[170]*V[1]*Pow(V[3],2)*V[122]*Pow(V[119],2)*V[173]+2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*V[121]*Pow(V[120],2)-2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[122]*Pow(V[120],2)*V[173]+2*Pow(V[167],2)*V[1]*V[17]*V[8]*V[122]*V[119]*V[120]*V[16]+2*Pow(V[167],2)*V[168]*V[172]*V[17]*V[3]*V[8]*M_SQRT2*V[123]*V[119]*V[120]-2*Pow(V[167],2)*V[23]*V[1]*V[8]*V[121]*V[119]*V[120]-2*Pow(V[167],2)*V[1]*Pow(V[8],2)*V[121])/(2)/(Pow(V[72],2));
   if(!isfinite(V[283]) || FError) return 283;
   nCurrentVars=284;
   V[284]=1/(Pow(V[167],2))/(V[3])/(V[168])/(V[172])*(4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[121]*Pow(V[109],2)*V[173]-3*V[172]*V[1]*Pow(V[3],2)*V[121]*Pow(V[109],2)*V[173]-4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[122]*Pow(V[109],2)+3*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[122]*Pow(V[109],2)-4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[121]*Pow(V[110],2)*V[173]+4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[122]*Pow(V[110],2)+6*Pow(V[167],2)*V[1]*V[17]*V[237]*V[121]*V[109]*V[110]*V[16]+6*Pow(V[167],2)*V[168]*V[17]*V[3]*V[237]*M_SQRT2*V[123]*V[109]*V[110]*V[173]-6*Pow(V[167],2)*V[21]*V[1]*V[237]*V[122]*V[109]*V[110]-6*Pow(V[167],2)*V[1]*Pow(V[237],2)*V[122])/(6)/(Pow(V[63],2));
   if(!isfinite(V[284]) || FError) return 284;
   nCurrentVars=285;
   V[285]=1/(Pow(V[167],2))/(V[3])/(V[168])/(V[172])*(4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[121]*Pow(V[111],2)*V[173]-3*V[172]*V[1]*Pow(V[3],2)*V[121]*Pow(V[111],2)*V[173]-4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[122]*Pow(V[111],2)+3*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[122]*Pow(V[111],2)-4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[121]*Pow(V[112],2)*V[173]+4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[122]*Pow(V[112],2)+6*Pow(V[167],2)*V[1]*V[17]*V[237]*V[121]*V[111]*V[112]*V[16]+6*Pow(V[167],2)*V[168]*V[17]*V[3]*V[237]*M_SQRT2*V[123]*V[111]*V[112]*V[173]-6*Pow(V[167],2)*V[21]*V[1]*V[237]*V[122]*V[111]*V[112]-6*Pow(V[167],2)*V[1]*Pow(V[237],2)*V[122])/(6)/(Pow(V[64],2));
   if(!isfinite(V[285]) || FError) return 285;
   nCurrentVars=286;
   V[286]=-1/(Pow(V[167],2))/(V[3])/(V[168])/(V[173])*(2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[113],2)*V[121]-3*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[113],2)*V[121]-2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[113],2)*V[122]*V[173]+3*V[172]*V[1]*Pow(V[3],2)*Pow(V[113],2)*V[122]*V[173]-2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[114],2)*V[121]+2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[114],2)*V[122]*V[173]-6*Pow(V[167],2)*V[1]*V[17]*V[236]*V[113]*V[114]*V[122]*V[16]-6*Pow(V[167],2)*V[168]*V[172]*V[17]*V[3]*V[236]*M_SQRT2*V[113]*V[114]*V[123]+6*Pow(V[167],2)*V[22]*V[1]*V[236]*V[113]*V[114]*V[121]+6*Pow(V[167],2)*V[1]*Pow(V[236],2)*V[121])/(6)/(Pow(V[65],2));
   if(!isfinite(V[286]) || FError) return 286;
   nCurrentVars=287;
   V[287]=-1/(Pow(V[167],2))/(V[3])/(V[168])/(V[173])*(2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[115],2)*V[121]-3*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[115],2)*V[121]-2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[115],2)*V[122]*V[173]+3*V[172]*V[1]*Pow(V[3],2)*Pow(V[115],2)*V[122]*V[173]-2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[116],2)*V[121]+2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[116],2)*V[122]*V[173]-6*Pow(V[167],2)*V[1]*V[17]*V[236]*V[115]*V[116]*V[122]*V[16]-6*Pow(V[167],2)*V[168]*V[172]*V[17]*V[3]*V[236]*M_SQRT2*V[115]*V[116]*V[123]+6*Pow(V[167],2)*V[22]*V[1]*V[236]*V[115]*V[116]*V[121]+6*Pow(V[167],2)*V[1]*Pow(V[236],2)*V[121])/(6)/(Pow(V[66],2));
   if(!isfinite(V[287]) || FError) return 287;
   nCurrentVars=288;
   V[288]=V[170]/(Pow(V[167],2))*V[1]*V[3]/(V[168])*(V[124]*V[173]-V[172]*V[125])/(2)/(Pow(V[67],2));
   if(!isfinite(V[288]) || FError) return 288;
   nCurrentVars=289;
   V[289]=1/(Pow(V[167],2))*V[1]*V[3]*V[168]*(V[124]*V[173]-V[172]*V[125])/(Pow(V[68],2));
   if(!isfinite(V[289]) || FError) return 289;
   nCurrentVars=290;
   V[290]=V[170]/(Pow(V[167],2))*V[1]*V[3]/(V[168])*(V[124]*V[173]-V[172]*V[125])/(2)/(Pow(V[69],2));
   if(!isfinite(V[290]) || FError) return 290;
   nCurrentVars=291;
   V[291]=1/(Pow(V[167],2))*V[1]*V[3]*V[168]*(V[124]*V[173]-V[172]*V[125])/(Pow(V[70],2));
   if(!isfinite(V[291]) || FError) return 291;
   nCurrentVars=292;
   V[292]=1/(Pow(V[167],2))/(V[3])/(V[168])/(V[172])*(4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[124]*Pow(V[220],2)*V[173]-3*V[172]*V[1]*Pow(V[3],2)*V[124]*Pow(V[220],2)*V[173]-4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[125]*Pow(V[220],2)+3*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[125]*Pow(V[220],2)-4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[124]*Pow(V[221],2)*V[173]+4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[125]*Pow(V[221],2)+6*Pow(V[167],2)*V[1]*V[17]*V[9]*V[124]*V[220]*V[221]*V[16]+6*Pow(V[167],2)*V[168]*V[17]*V[3]*V[9]*M_SQRT2*V[126]*V[220]*V[221]*V[173]-6*Pow(V[167],2)*V[164]*V[1]*V[9]*V[125]*V[220]*V[221]-6*Pow(V[167],2)*V[1]*Pow(V[9],2)*V[125])/(6)/(Pow(V[55],2));
   if(!isfinite(V[292]) || FError) return 292;
   nCurrentVars=293;
   V[293]=1/(Pow(V[167],2))/(V[3])/(V[168])/(V[172])*(4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[124]*Pow(V[222],2)*V[173]-3*V[172]*V[1]*Pow(V[3],2)*V[124]*Pow(V[222],2)*V[173]-4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[125]*Pow(V[222],2)+3*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[125]*Pow(V[222],2)-4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[124]*Pow(V[223],2)*V[173]+4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[125]*Pow(V[223],2)+6*Pow(V[167],2)*V[1]*V[17]*V[9]*V[124]*V[222]*V[223]*V[16]+6*Pow(V[167],2)*V[168]*V[17]*V[3]*V[9]*M_SQRT2*V[126]*V[222]*V[223]*V[173]-6*Pow(V[167],2)*V[164]*V[1]*V[9]*V[125]*V[222]*V[223]-6*Pow(V[167],2)*V[1]*Pow(V[9],2)*V[125])/(6)/(Pow(V[56],2));
   if(!isfinite(V[293]) || FError) return 293;
   nCurrentVars=294;
   V[294]=1/(Pow(V[167],2))/(V[3])/(V[168])/(V[172])*(4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[228],2)*V[124]*V[173]-3*V[172]*V[1]*Pow(V[3],2)*Pow(V[228],2)*V[124]*V[173]-4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*Pow(V[228],2)*V[125]+3*Pow(V[172],2)*V[1]*Pow(V[3],2)*Pow(V[228],2)*V[125]-4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[229],2)*V[124]*V[173]+4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*Pow(V[229],2)*V[125]+6*Pow(V[167],2)*V[1]*V[17]*V[211]*V[228]*V[229]*V[124]*V[16]+6*Pow(V[167],2)*V[168]*V[17]*V[3]*V[211]*M_SQRT2*V[228]*V[229]*V[126]*V[173]-6*Pow(V[167],2)*V[164]*V[1]*V[211]*V[228]*V[229]*V[125]-6*Pow(V[167],2)*V[1]*Pow(V[211],2)*V[125])/(6)/(Pow(V[59],2));
   if(!isfinite(V[294]) || FError) return 294;
   nCurrentVars=295;
   V[295]=1/(Pow(V[167],2))/(V[3])/(V[168])/(V[172])*(4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[230],2)*V[124]*V[173]-3*V[172]*V[1]*Pow(V[3],2)*Pow(V[230],2)*V[124]*V[173]-4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*Pow(V[230],2)*V[125]+3*Pow(V[172],2)*V[1]*Pow(V[3],2)*Pow(V[230],2)*V[125]-4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[231],2)*V[124]*V[173]+4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*Pow(V[231],2)*V[125]+6*Pow(V[167],2)*V[1]*V[17]*V[211]*V[230]*V[231]*V[124]*V[16]+6*Pow(V[167],2)*V[168]*V[17]*V[3]*V[211]*M_SQRT2*V[230]*V[231]*V[126]*V[173]-6*Pow(V[167],2)*V[164]*V[1]*V[211]*V[230]*V[231]*V[125]-6*Pow(V[167],2)*V[1]*Pow(V[211],2)*V[125])/(6)/(Pow(V[60],2));
   if(!isfinite(V[295]) || FError) return 295;
   nCurrentVars=296;
   V[296]=-1/(Pow(V[167],2))/(V[3])/(V[168])/(V[173])*(2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[224],2)*V[124]-3*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[224],2)*V[124]-2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[224],2)*V[125]*V[173]+3*V[172]*V[1]*Pow(V[3],2)*Pow(V[224],2)*V[125]*V[173]-2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[225],2)*V[124]+2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[225],2)*V[125]*V[173]-6*Pow(V[167],2)*V[1]*V[17]*V[9]*V[224]*V[225]*V[125]*V[16]-6*Pow(V[167],2)*V[168]*V[172]*V[17]*V[3]*V[9]*M_SQRT2*V[224]*V[225]*V[126]+6*Pow(V[167],2)*V[165]*V[1]*V[9]*V[224]*V[225]*V[124]+6*Pow(V[167],2)*V[1]*Pow(V[9],2)*V[124])/(6)/(Pow(V[57],2));
   if(!isfinite(V[296]) || FError) return 296;
   nCurrentVars=297;
   V[297]=-1/(Pow(V[167],2))/(V[3])/(V[168])/(V[173])*(2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[226],2)*V[124]-3*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[226],2)*V[124]-2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[226],2)*V[125]*V[173]+3*V[172]*V[1]*Pow(V[3],2)*Pow(V[226],2)*V[125]*V[173]-2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[227],2)*V[124]+2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[227],2)*V[125]*V[173]-6*Pow(V[167],2)*V[1]*V[17]*V[9]*V[226]*V[227]*V[125]*V[16]-6*Pow(V[167],2)*V[168]*V[172]*V[17]*V[3]*V[9]*M_SQRT2*V[226]*V[227]*V[126]+6*Pow(V[167],2)*V[165]*V[1]*V[9]*V[226]*V[227]*V[124]+6*Pow(V[167],2)*V[1]*Pow(V[9],2)*V[124])/(6)/(Pow(V[58],2));
   if(!isfinite(V[297]) || FError) return 297;
   nCurrentVars=298;
   V[298]=-1/(Pow(V[167],2))/(V[3])/(V[168])/(V[173])*(2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*V[124]*Pow(V[232],2)-3*Pow(V[173],2)*V[1]*Pow(V[3],2)*V[124]*Pow(V[232],2)-2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[125]*Pow(V[232],2)*V[173]+3*V[172]*V[1]*Pow(V[3],2)*V[125]*Pow(V[232],2)*V[173]-2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*V[124]*Pow(V[233],2)+2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[125]*Pow(V[233],2)*V[173]-6*Pow(V[167],2)*V[1]*V[17]*V[9]*V[125]*V[232]*V[233]*V[16]-6*Pow(V[167],2)*V[168]*V[172]*V[17]*V[3]*V[9]*M_SQRT2*V[126]*V[232]*V[233]+6*Pow(V[167],2)*V[165]*V[1]*V[9]*V[124]*V[232]*V[233]+6*Pow(V[167],2)*V[1]*Pow(V[9],2)*V[124])/(6)/(Pow(V[61],2));
   if(!isfinite(V[298]) || FError) return 298;
   nCurrentVars=299;
   V[299]=-1/(Pow(V[167],2))/(V[3])/(V[168])/(V[173])*(2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*V[124]*Pow(V[234],2)-3*Pow(V[173],2)*V[1]*Pow(V[3],2)*V[124]*Pow(V[234],2)-2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[125]*Pow(V[234],2)*V[173]+3*V[172]*V[1]*Pow(V[3],2)*V[125]*Pow(V[234],2)*V[173]-2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*V[124]*Pow(V[235],2)+2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[125]*Pow(V[235],2)*V[173]-6*Pow(V[167],2)*V[1]*V[17]*V[9]*V[125]*V[234]*V[235]*V[16]-6*Pow(V[167],2)*V[168]*V[172]*V[17]*V[3]*V[9]*M_SQRT2*V[126]*V[234]*V[235]+6*Pow(V[167],2)*V[165]*V[1]*V[9]*V[124]*V[234]*V[235]+6*Pow(V[167],2)*V[1]*Pow(V[9],2)*V[124])/(6)/(Pow(V[62],2));
   if(!isfinite(V[299]) || FError) return 299;
   nCurrentVars=300;
   V[300]=1/(Pow(V[167],2))/(V[3])/(V[168])/(V[173])*(Pow(V[173],2)*V[170]*V[1]*Pow(V[3],2)*V[124]*Pow(V[117],2)-V[172]*V[170]*V[1]*Pow(V[3],2)*V[125]*Pow(V[117],2)*V[173]+2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*V[124]*Pow(V[118],2)-2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[125]*Pow(V[118],2)*V[173]+2*Pow(V[167],2)*V[1]*V[17]*V[8]*V[125]*V[117]*V[118]*V[16]+2*Pow(V[167],2)*V[168]*V[172]*V[17]*V[3]*V[8]*M_SQRT2*V[126]*V[117]*V[118]-2*Pow(V[167],2)*V[23]*V[1]*V[8]*V[124]*V[117]*V[118]-2*Pow(V[167],2)*V[1]*Pow(V[8],2)*V[124])/(2)/(Pow(V[71],2));
   if(!isfinite(V[300]) || FError) return 300;
   nCurrentVars=301;
   V[301]=1/(Pow(V[167],2))/(V[3])/(V[168])/(V[173])*(Pow(V[173],2)*V[170]*V[1]*Pow(V[3],2)*V[124]*Pow(V[119],2)-V[172]*V[170]*V[1]*Pow(V[3],2)*V[125]*Pow(V[119],2)*V[173]+2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*V[124]*Pow(V[120],2)-2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[125]*Pow(V[120],2)*V[173]+2*Pow(V[167],2)*V[1]*V[17]*V[8]*V[125]*V[119]*V[120]*V[16]+2*Pow(V[167],2)*V[168]*V[172]*V[17]*V[3]*V[8]*M_SQRT2*V[126]*V[119]*V[120]-2*Pow(V[167],2)*V[23]*V[1]*V[8]*V[124]*V[119]*V[120]-2*Pow(V[167],2)*V[1]*Pow(V[8],2)*V[124])/(2)/(Pow(V[72],2));
   if(!isfinite(V[301]) || FError) return 301;
   nCurrentVars=302;
   V[302]=1/(Pow(V[167],2))/(V[3])/(V[168])/(V[172])*(4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[124]*Pow(V[109],2)*V[173]-3*V[172]*V[1]*Pow(V[3],2)*V[124]*Pow(V[109],2)*V[173]-4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[125]*Pow(V[109],2)+3*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[125]*Pow(V[109],2)-4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[124]*Pow(V[110],2)*V[173]+4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[125]*Pow(V[110],2)+6*Pow(V[167],2)*V[1]*V[17]*V[237]*V[124]*V[109]*V[110]*V[16]+6*Pow(V[167],2)*V[168]*V[17]*V[3]*V[237]*M_SQRT2*V[126]*V[109]*V[110]*V[173]-6*Pow(V[167],2)*V[21]*V[1]*V[237]*V[125]*V[109]*V[110]-6*Pow(V[167],2)*V[1]*Pow(V[237],2)*V[125])/(6)/(Pow(V[63],2));
   if(!isfinite(V[302]) || FError) return 302;
   nCurrentVars=303;
   V[303]=1/(Pow(V[167],2))/(V[3])/(V[168])/(V[172])*(4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[124]*Pow(V[111],2)*V[173]-3*V[172]*V[1]*Pow(V[3],2)*V[124]*Pow(V[111],2)*V[173]-4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[125]*Pow(V[111],2)+3*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[125]*Pow(V[111],2)-4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[124]*Pow(V[112],2)*V[173]+4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[125]*Pow(V[112],2)+6*Pow(V[167],2)*V[1]*V[17]*V[237]*V[124]*V[111]*V[112]*V[16]+6*Pow(V[167],2)*V[168]*V[17]*V[3]*V[237]*M_SQRT2*V[126]*V[111]*V[112]*V[173]-6*Pow(V[167],2)*V[21]*V[1]*V[237]*V[125]*V[111]*V[112]-6*Pow(V[167],2)*V[1]*Pow(V[237],2)*V[125])/(6)/(Pow(V[64],2));
   if(!isfinite(V[303]) || FError) return 303;
   nCurrentVars=304;
   V[304]=-1/(Pow(V[167],2))/(V[3])/(V[168])/(V[173])*(2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[113],2)*V[124]-3*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[113],2)*V[124]-2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[113],2)*V[125]*V[173]+3*V[172]*V[1]*Pow(V[3],2)*Pow(V[113],2)*V[125]*V[173]-2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[114],2)*V[124]+2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[114],2)*V[125]*V[173]-6*Pow(V[167],2)*V[1]*V[17]*V[236]*V[113]*V[114]*V[125]*V[16]-6*Pow(V[167],2)*V[168]*V[172]*V[17]*V[3]*V[236]*M_SQRT2*V[113]*V[114]*V[126]+6*Pow(V[167],2)*V[22]*V[1]*V[236]*V[113]*V[114]*V[124]+6*Pow(V[167],2)*V[1]*Pow(V[236],2)*V[124])/(6)/(Pow(V[65],2));
   if(!isfinite(V[304]) || FError) return 304;
   nCurrentVars=305;
   V[305]=-1/(Pow(V[167],2))/(V[3])/(V[168])/(V[173])*(2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[115],2)*V[124]-3*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[115],2)*V[124]-2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[115],2)*V[125]*V[173]+3*V[172]*V[1]*Pow(V[3],2)*Pow(V[115],2)*V[125]*V[173]-2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[116],2)*V[124]+2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[116],2)*V[125]*V[173]-6*Pow(V[167],2)*V[1]*V[17]*V[236]*V[115]*V[116]*V[125]*V[16]-6*Pow(V[167],2)*V[168]*V[172]*V[17]*V[3]*V[236]*M_SQRT2*V[115]*V[116]*V[126]+6*Pow(V[167],2)*V[22]*V[1]*V[236]*V[115]*V[116]*V[124]+6*Pow(V[167],2)*V[1]*Pow(V[236],2)*V[124])/(6)/(Pow(V[66],2));
   if(!isfinite(V[305]) || FError) return 305;
   nCurrentVars=306;
   V[306]=V[170]/(Pow(V[167],2))*V[1]*V[3]/(V[168])*(V[127]*V[173]-V[172]*V[128])/(2)/(Pow(V[67],2));
   if(!isfinite(V[306]) || FError) return 306;
   nCurrentVars=307;
   V[307]=1/(Pow(V[167],2))*V[1]*V[3]*V[168]*(V[127]*V[173]-V[172]*V[128])/(Pow(V[68],2));
   if(!isfinite(V[307]) || FError) return 307;
   nCurrentVars=308;
   V[308]=V[170]/(Pow(V[167],2))*V[1]*V[3]/(V[168])*(V[127]*V[173]-V[172]*V[128])/(2)/(Pow(V[69],2));
   if(!isfinite(V[308]) || FError) return 308;
   nCurrentVars=309;
   V[309]=1/(Pow(V[167],2))*V[1]*V[3]*V[168]*(V[127]*V[173]-V[172]*V[128])/(Pow(V[70],2));
   if(!isfinite(V[309]) || FError) return 309;
   nCurrentVars=310;
   V[310]=1/(Pow(V[167],2))/(V[3])/(V[168])/(V[172])*(4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[127]*Pow(V[220],2)*V[173]-3*V[172]*V[1]*Pow(V[3],2)*V[127]*Pow(V[220],2)*V[173]-4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[128]*Pow(V[220],2)+3*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[128]*Pow(V[220],2)-4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[127]*Pow(V[221],2)*V[173]+4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[128]*Pow(V[221],2)+6*Pow(V[167],2)*V[1]*V[17]*V[9]*V[127]*V[220]*V[221]*V[16]+6*Pow(V[167],2)*V[168]*V[17]*V[3]*V[9]*M_SQRT2*V[129]*V[220]*V[221]*V[173]-6*Pow(V[167],2)*V[164]*V[1]*V[9]*V[128]*V[220]*V[221]-6*Pow(V[167],2)*V[1]*Pow(V[9],2)*V[128])/(6)/(Pow(V[55],2));
   if(!isfinite(V[310]) || FError) return 310;
   nCurrentVars=311;
   V[311]=1/(Pow(V[167],2))/(V[3])/(V[168])/(V[172])*(4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[127]*Pow(V[222],2)*V[173]-3*V[172]*V[1]*Pow(V[3],2)*V[127]*Pow(V[222],2)*V[173]-4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[128]*Pow(V[222],2)+3*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[128]*Pow(V[222],2)-4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[127]*Pow(V[223],2)*V[173]+4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[128]*Pow(V[223],2)+6*Pow(V[167],2)*V[1]*V[17]*V[9]*V[127]*V[222]*V[223]*V[16]+6*Pow(V[167],2)*V[168]*V[17]*V[3]*V[9]*M_SQRT2*V[129]*V[222]*V[223]*V[173]-6*Pow(V[167],2)*V[164]*V[1]*V[9]*V[128]*V[222]*V[223]-6*Pow(V[167],2)*V[1]*Pow(V[9],2)*V[128])/(6)/(Pow(V[56],2));
   if(!isfinite(V[311]) || FError) return 311;
   nCurrentVars=312;
   V[312]=1/(Pow(V[167],2))/(V[3])/(V[168])/(V[172])*(4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[228],2)*V[127]*V[173]-3*V[172]*V[1]*Pow(V[3],2)*Pow(V[228],2)*V[127]*V[173]-4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*Pow(V[228],2)*V[128]+3*Pow(V[172],2)*V[1]*Pow(V[3],2)*Pow(V[228],2)*V[128]-4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[229],2)*V[127]*V[173]+4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*Pow(V[229],2)*V[128]+6*Pow(V[167],2)*V[1]*V[17]*V[211]*V[228]*V[229]*V[127]*V[16]+6*Pow(V[167],2)*V[168]*V[17]*V[3]*V[211]*M_SQRT2*V[228]*V[229]*V[129]*V[173]-6*Pow(V[167],2)*V[164]*V[1]*V[211]*V[228]*V[229]*V[128]-6*Pow(V[167],2)*V[1]*Pow(V[211],2)*V[128])/(6)/(Pow(V[59],2));
   if(!isfinite(V[312]) || FError) return 312;
   nCurrentVars=313;
   V[313]=1/(Pow(V[167],2))/(V[3])/(V[168])/(V[172])*(4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[230],2)*V[127]*V[173]-3*V[172]*V[1]*Pow(V[3],2)*Pow(V[230],2)*V[127]*V[173]-4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*Pow(V[230],2)*V[128]+3*Pow(V[172],2)*V[1]*Pow(V[3],2)*Pow(V[230],2)*V[128]-4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[231],2)*V[127]*V[173]+4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*Pow(V[231],2)*V[128]+6*Pow(V[167],2)*V[1]*V[17]*V[211]*V[230]*V[231]*V[127]*V[16]+6*Pow(V[167],2)*V[168]*V[17]*V[3]*V[211]*M_SQRT2*V[230]*V[231]*V[129]*V[173]-6*Pow(V[167],2)*V[164]*V[1]*V[211]*V[230]*V[231]*V[128]-6*Pow(V[167],2)*V[1]*Pow(V[211],2)*V[128])/(6)/(Pow(V[60],2));
   if(!isfinite(V[313]) || FError) return 313;
   nCurrentVars=314;
   V[314]=-1/(Pow(V[167],2))/(V[3])/(V[168])/(V[173])*(2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[224],2)*V[127]-3*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[224],2)*V[127]-2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[224],2)*V[128]*V[173]+3*V[172]*V[1]*Pow(V[3],2)*Pow(V[224],2)*V[128]*V[173]-2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[225],2)*V[127]+2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[225],2)*V[128]*V[173]-6*Pow(V[167],2)*V[1]*V[17]*V[9]*V[224]*V[225]*V[128]*V[16]-6*Pow(V[167],2)*V[168]*V[172]*V[17]*V[3]*V[9]*M_SQRT2*V[224]*V[225]*V[129]+6*Pow(V[167],2)*V[165]*V[1]*V[9]*V[224]*V[225]*V[127]+6*Pow(V[167],2)*V[1]*Pow(V[9],2)*V[127])/(6)/(Pow(V[57],2));
   if(!isfinite(V[314]) || FError) return 314;
   nCurrentVars=315;
   V[315]=-1/(Pow(V[167],2))/(V[3])/(V[168])/(V[173])*(2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[226],2)*V[127]-3*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[226],2)*V[127]-2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[226],2)*V[128]*V[173]+3*V[172]*V[1]*Pow(V[3],2)*Pow(V[226],2)*V[128]*V[173]-2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[227],2)*V[127]+2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[227],2)*V[128]*V[173]-6*Pow(V[167],2)*V[1]*V[17]*V[9]*V[226]*V[227]*V[128]*V[16]-6*Pow(V[167],2)*V[168]*V[172]*V[17]*V[3]*V[9]*M_SQRT2*V[226]*V[227]*V[129]+6*Pow(V[167],2)*V[165]*V[1]*V[9]*V[226]*V[227]*V[127]+6*Pow(V[167],2)*V[1]*Pow(V[9],2)*V[127])/(6)/(Pow(V[58],2));
   if(!isfinite(V[315]) || FError) return 315;
   nCurrentVars=316;
   V[316]=-1/(Pow(V[167],2))/(V[3])/(V[168])/(V[173])*(2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*V[127]*Pow(V[232],2)-3*Pow(V[173],2)*V[1]*Pow(V[3],2)*V[127]*Pow(V[232],2)-2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[128]*Pow(V[232],2)*V[173]+3*V[172]*V[1]*Pow(V[3],2)*V[128]*Pow(V[232],2)*V[173]-2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*V[127]*Pow(V[233],2)+2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[128]*Pow(V[233],2)*V[173]-6*Pow(V[167],2)*V[1]*V[17]*V[9]*V[128]*V[232]*V[233]*V[16]-6*Pow(V[167],2)*V[168]*V[172]*V[17]*V[3]*V[9]*M_SQRT2*V[129]*V[232]*V[233]+6*Pow(V[167],2)*V[165]*V[1]*V[9]*V[127]*V[232]*V[233]+6*Pow(V[167],2)*V[1]*Pow(V[9],2)*V[127])/(6)/(Pow(V[61],2));
   if(!isfinite(V[316]) || FError) return 316;
   nCurrentVars=317;
   V[317]=-1/(Pow(V[167],2))/(V[3])/(V[168])/(V[173])*(2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*V[127]*Pow(V[234],2)-3*Pow(V[173],2)*V[1]*Pow(V[3],2)*V[127]*Pow(V[234],2)-2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[128]*Pow(V[234],2)*V[173]+3*V[172]*V[1]*Pow(V[3],2)*V[128]*Pow(V[234],2)*V[173]-2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*V[127]*Pow(V[235],2)+2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[128]*Pow(V[235],2)*V[173]-6*Pow(V[167],2)*V[1]*V[17]*V[9]*V[128]*V[234]*V[235]*V[16]-6*Pow(V[167],2)*V[168]*V[172]*V[17]*V[3]*V[9]*M_SQRT2*V[129]*V[234]*V[235]+6*Pow(V[167],2)*V[165]*V[1]*V[9]*V[127]*V[234]*V[235]+6*Pow(V[167],2)*V[1]*Pow(V[9],2)*V[127])/(6)/(Pow(V[62],2));
   if(!isfinite(V[317]) || FError) return 317;
   nCurrentVars=318;
   V[318]=1/(Pow(V[167],2))/(V[3])/(V[168])/(V[173])*(Pow(V[173],2)*V[170]*V[1]*Pow(V[3],2)*V[127]*Pow(V[117],2)-V[172]*V[170]*V[1]*Pow(V[3],2)*V[128]*Pow(V[117],2)*V[173]+2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*V[127]*Pow(V[118],2)-2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[128]*Pow(V[118],2)*V[173]+2*Pow(V[167],2)*V[1]*V[17]*V[8]*V[128]*V[117]*V[118]*V[16]+2*Pow(V[167],2)*V[168]*V[172]*V[17]*V[3]*V[8]*M_SQRT2*V[129]*V[117]*V[118]-2*Pow(V[167],2)*V[23]*V[1]*V[8]*V[127]*V[117]*V[118]-2*Pow(V[167],2)*V[1]*Pow(V[8],2)*V[127])/(2)/(Pow(V[71],2));
   if(!isfinite(V[318]) || FError) return 318;
   nCurrentVars=319;
   V[319]=1/(Pow(V[167],2))/(V[3])/(V[168])/(V[173])*(Pow(V[173],2)*V[170]*V[1]*Pow(V[3],2)*V[127]*Pow(V[119],2)-V[172]*V[170]*V[1]*Pow(V[3],2)*V[128]*Pow(V[119],2)*V[173]+2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*V[127]*Pow(V[120],2)-2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[128]*Pow(V[120],2)*V[173]+2*Pow(V[167],2)*V[1]*V[17]*V[8]*V[128]*V[119]*V[120]*V[16]+2*Pow(V[167],2)*V[168]*V[172]*V[17]*V[3]*V[8]*M_SQRT2*V[129]*V[119]*V[120]-2*Pow(V[167],2)*V[23]*V[1]*V[8]*V[127]*V[119]*V[120]-2*Pow(V[167],2)*V[1]*Pow(V[8],2)*V[127])/(2)/(Pow(V[72],2));
   if(!isfinite(V[319]) || FError) return 319;
   nCurrentVars=320;
   V[320]=1/(Pow(V[167],2))/(V[3])/(V[168])/(V[172])*(4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[127]*Pow(V[109],2)*V[173]-3*V[172]*V[1]*Pow(V[3],2)*V[127]*Pow(V[109],2)*V[173]-4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[128]*Pow(V[109],2)+3*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[128]*Pow(V[109],2)-4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[127]*Pow(V[110],2)*V[173]+4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[128]*Pow(V[110],2)+6*Pow(V[167],2)*V[1]*V[17]*V[237]*V[127]*V[109]*V[110]*V[16]+6*Pow(V[167],2)*V[168]*V[17]*V[3]*V[237]*M_SQRT2*V[129]*V[109]*V[110]*V[173]-6*Pow(V[167],2)*V[21]*V[1]*V[237]*V[128]*V[109]*V[110]-6*Pow(V[167],2)*V[1]*Pow(V[237],2)*V[128])/(6)/(Pow(V[63],2));
   if(!isfinite(V[320]) || FError) return 320;
   nCurrentVars=321;
   V[321]=1/(Pow(V[167],2))/(V[3])/(V[168])/(V[172])*(4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[127]*Pow(V[111],2)*V[173]-3*V[172]*V[1]*Pow(V[3],2)*V[127]*Pow(V[111],2)*V[173]-4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[128]*Pow(V[111],2)+3*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[128]*Pow(V[111],2)-4*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*V[127]*Pow(V[112],2)*V[173]+4*Pow(V[168],2)*Pow(V[172],2)*V[1]*Pow(V[3],2)*V[128]*Pow(V[112],2)+6*Pow(V[167],2)*V[1]*V[17]*V[237]*V[127]*V[111]*V[112]*V[16]+6*Pow(V[167],2)*V[168]*V[17]*V[3]*V[237]*M_SQRT2*V[129]*V[111]*V[112]*V[173]-6*Pow(V[167],2)*V[21]*V[1]*V[237]*V[128]*V[111]*V[112]-6*Pow(V[167],2)*V[1]*Pow(V[237],2)*V[128])/(6)/(Pow(V[64],2));
   if(!isfinite(V[321]) || FError) return 321;
   nCurrentVars=322;
   V[322]=-1/(Pow(V[167],2))/(V[3])/(V[168])/(V[173])*(2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[113],2)*V[127]-3*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[113],2)*V[127]-2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[113],2)*V[128]*V[173]+3*V[172]*V[1]*Pow(V[3],2)*Pow(V[113],2)*V[128]*V[173]-2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[114],2)*V[127]+2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[114],2)*V[128]*V[173]-6*Pow(V[167],2)*V[1]*V[17]*V[236]*V[113]*V[114]*V[128]*V[16]-6*Pow(V[167],2)*V[168]*V[172]*V[17]*V[3]*V[236]*M_SQRT2*V[113]*V[114]*V[129]+6*Pow(V[167],2)*V[22]*V[1]*V[236]*V[113]*V[114]*V[127]+6*Pow(V[167],2)*V[1]*Pow(V[236],2)*V[127])/(6)/(Pow(V[65],2));
   if(!isfinite(V[322]) || FError) return 322;
   nCurrentVars=323;
   V[323]=-1/(Pow(V[167],2))/(V[3])/(V[168])/(V[173])*(2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[115],2)*V[127]-3*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[115],2)*V[127]-2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[115],2)*V[128]*V[173]+3*V[172]*V[1]*Pow(V[3],2)*Pow(V[115],2)*V[128]*V[173]-2*Pow(V[168],2)*Pow(V[173],2)*V[1]*Pow(V[3],2)*Pow(V[116],2)*V[127]+2*Pow(V[168],2)*V[172]*V[1]*Pow(V[3],2)*Pow(V[116],2)*V[128]*V[173]-6*Pow(V[167],2)*V[1]*V[17]*V[236]*V[115]*V[116]*V[128]*V[16]-6*Pow(V[167],2)*V[168]*V[172]*V[17]*V[3]*V[236]*M_SQRT2*V[115]*V[116]*V[129]+6*Pow(V[167],2)*V[22]*V[1]*V[236]*V[115]*V[116]*V[127]+6*Pow(V[167],2)*V[1]*Pow(V[236],2)*V[127])/(6)/(Pow(V[66],2));
   if(!isfinite(V[323]) || FError) return 323;
   nCurrentVars=324;
   V[324]=V[1]*V[3]/(V[168])*(V[121]*V[173]+V[172]*V[122])/(Pow(V[3],2));
   if(!isfinite(V[324]) || FError) return 324;
   nCurrentVars=325;
   V[325]=2*V[168]*Pow(V[172],2)*V[3]*V[121]*V[173]*V[136]+2*V[168]*Pow(V[173],2)*V[172]*V[3]*V[122]*V[137]+2*V[168]*Pow(V[173],2)*V[3]*V[121]*V[173]*V[138]+2*V[168]*Pow(V[172],3)*V[3]*V[122]*V[138]-2*V[168]*Pow(V[173],2)*V[172]*V[3]*V[122]*V[139];
   if(!isfinite(V[325]) || FError) return 325;
   nCurrentVars=326;
   V[326]=V[325]-2*V[168]*Pow(V[172],2)*V[3]*V[121]*V[173]*V[139]-2*V[168]*Pow(V[173],2)*V[172]*V[3]*V[122]*V[140]-2*V[168]*Pow(V[172],2)*V[3]*V[121]*V[173]*V[140]-6*V[168]*Pow(V[172],3)*V[3]*V[121]*V[141]+4*V[168]*V[172]*V[3]*V[121]*V[141];
   if(!isfinite(V[326]) || FError) return 326;
   nCurrentVars=327;
   V[327]=V[326]-2*V[168]*Pow(V[172],2)*V[3]*V[122]*V[173]*V[141]+6*V[168]*Pow(V[172],2)*V[3]*V[122]*V[173]*V[142]-2*V[168]*V[3]*V[122]*V[173]*V[142]-2*V[168]*Pow(V[173],2)*V[172]*V[3]*V[121]*V[142]+Pow(V[172],2)*V[1]*M_SQRT2*V[123]*V[143]*V[16];
   if(!isfinite(V[327]) || FError) return 327;
   nCurrentVars=328;
   V[328]=V[327]+Pow(V[173],2)*V[1]*M_SQRT2*V[123]*V[144]*V[16]+2*V[172]*V[1]*M_SQRT2*V[123]*V[173]*V[146]*V[16]+2*V[172]*V[1]*M_SQRT2*V[123]*V[173]*V[147]*V[16]+2*V[172]*V[1]*M_SQRT2*V[123]*V[173]*V[148]*V[16]+Pow(V[172],2)*V[1]*M_SQRT2*V[123]*V[151];
   if(!isfinite(V[328]) || FError) return 328;
   nCurrentVars=329;
   V[329]=V[328]+Pow(V[173],2)*V[1]*M_SQRT2*V[123]*V[152]+V[172]*V[1]*M_SQRT2*V[123]*V[155]*V[173]+V[172]*V[1]*M_SQRT2*V[123]*V[156]*V[173];
   if(!isfinite(V[329]) || FError) return 329;
   nCurrentVars=330;
   V[330]=-1/(V[1])*V[329]/(Pow(V[46],2));
   if(!isfinite(V[330]) || FError) return 330;
   nCurrentVars=331;
   V[331]=V[1]*V[3]/(V[168])*(V[124]*V[173]+V[172]*V[125])/(Pow(V[3],2));
   if(!isfinite(V[331]) || FError) return 331;
   nCurrentVars=332;
   V[332]=2*V[168]*Pow(V[172],2)*V[3]*V[124]*V[173]*V[136]+2*V[168]*Pow(V[173],2)*V[172]*V[3]*V[125]*V[137]+2*V[168]*Pow(V[173],2)*V[3]*V[124]*V[173]*V[138]+2*V[168]*Pow(V[172],3)*V[3]*V[125]*V[138]-2*V[168]*Pow(V[173],2)*V[172]*V[3]*V[125]*V[139];
   if(!isfinite(V[332]) || FError) return 332;
   nCurrentVars=333;
   V[333]=V[332]-2*V[168]*Pow(V[172],2)*V[3]*V[124]*V[173]*V[139]-2*V[168]*Pow(V[173],2)*V[172]*V[3]*V[125]*V[140]-2*V[168]*Pow(V[172],2)*V[3]*V[124]*V[173]*V[140]-6*V[168]*Pow(V[172],3)*V[3]*V[124]*V[141]+4*V[168]*V[172]*V[3]*V[124]*V[141];
   if(!isfinite(V[333]) || FError) return 333;
   nCurrentVars=334;
   V[334]=V[333]-2*V[168]*Pow(V[172],2)*V[3]*V[125]*V[173]*V[141]+6*V[168]*Pow(V[172],2)*V[3]*V[125]*V[173]*V[142]-2*V[168]*V[3]*V[125]*V[173]*V[142]-2*V[168]*Pow(V[173],2)*V[172]*V[3]*V[124]*V[142]+Pow(V[172],2)*V[1]*M_SQRT2*V[126]*V[143]*V[16];
   if(!isfinite(V[334]) || FError) return 334;
   nCurrentVars=335;
   V[335]=V[334]+Pow(V[173],2)*V[1]*M_SQRT2*V[126]*V[144]*V[16]+2*V[172]*V[1]*M_SQRT2*V[126]*V[173]*V[146]*V[16]+2*V[172]*V[1]*M_SQRT2*V[126]*V[173]*V[147]*V[16]+2*V[172]*V[1]*M_SQRT2*V[126]*V[173]*V[148]*V[16]+Pow(V[172],2)*V[1]*M_SQRT2*V[126]*V[151];
   if(!isfinite(V[335]) || FError) return 335;
   nCurrentVars=336;
   V[336]=V[335]+Pow(V[173],2)*V[1]*M_SQRT2*V[126]*V[152]+V[172]*V[1]*M_SQRT2*V[126]*V[155]*V[173]+V[172]*V[1]*M_SQRT2*V[126]*V[156]*V[173];
   if(!isfinite(V[336]) || FError) return 336;
   nCurrentVars=337;
   V[337]=-1/(V[1])*V[336]/(Pow(V[46],2));
   if(!isfinite(V[337]) || FError) return 337;
   nCurrentVars=338;
   V[338]=V[1]*V[3]/(V[168])*(V[127]*V[173]+V[172]*V[128])/(Pow(V[3],2));
   if(!isfinite(V[338]) || FError) return 338;
   nCurrentVars=339;
   V[339]=2*V[168]*Pow(V[172],2)*V[3]*V[127]*V[173]*V[136]+2*V[168]*Pow(V[173],2)*V[172]*V[3]*V[128]*V[137]+2*V[168]*Pow(V[173],2)*V[3]*V[127]*V[173]*V[138]+2*V[168]*Pow(V[172],3)*V[3]*V[128]*V[138]-2*V[168]*Pow(V[173],2)*V[172]*V[3]*V[128]*V[139];
   if(!isfinite(V[339]) || FError) return 339;
   nCurrentVars=340;
   V[340]=V[339]-2*V[168]*Pow(V[172],2)*V[3]*V[127]*V[173]*V[139]-2*V[168]*Pow(V[173],2)*V[172]*V[3]*V[128]*V[140]-2*V[168]*Pow(V[172],2)*V[3]*V[127]*V[173]*V[140]-6*V[168]*Pow(V[172],3)*V[3]*V[127]*V[141]+4*V[168]*V[172]*V[3]*V[127]*V[141];
   if(!isfinite(V[340]) || FError) return 340;
   nCurrentVars=341;
   V[341]=V[340]-2*V[168]*Pow(V[172],2)*V[3]*V[128]*V[173]*V[141]+6*V[168]*Pow(V[172],2)*V[3]*V[128]*V[173]*V[142]-2*V[168]*V[3]*V[128]*V[173]*V[142]-2*V[168]*Pow(V[173],2)*V[172]*V[3]*V[127]*V[142]+Pow(V[172],2)*V[1]*M_SQRT2*V[129]*V[143]*V[16];
   if(!isfinite(V[341]) || FError) return 341;
   nCurrentVars=342;
   V[342]=V[341]+Pow(V[173],2)*V[1]*M_SQRT2*V[129]*V[144]*V[16]+2*V[172]*V[1]*M_SQRT2*V[129]*V[173]*V[146]*V[16]+2*V[172]*V[1]*M_SQRT2*V[129]*V[173]*V[147]*V[16]+2*V[172]*V[1]*M_SQRT2*V[129]*V[173]*V[148]*V[16]+Pow(V[172],2)*V[1]*M_SQRT2*V[129]*V[151];
   if(!isfinite(V[342]) || FError) return 342;
   nCurrentVars=343;
   V[343]=V[342]+Pow(V[173],2)*V[1]*M_SQRT2*V[129]*V[152]+V[172]*V[1]*M_SQRT2*V[129]*V[155]*V[173]+V[172]*V[1]*M_SQRT2*V[129]*V[156]*V[173];
   if(!isfinite(V[343]) || FError) return 343;
   nCurrentVars=344;
   V[344]=-1/(V[1])*V[343]/(Pow(V[46],2));
   if(!isfinite(V[344]) || FError) return 344;
   nCurrentVars=345;
   V[345]=1/(V[3])/(V[168])*M_SQRT2/(V[173])/(V[172])/(V[16])*(V[168]*V[172]*V[3]*V[248]*V[123]*V[102]*V[106]*V[173]-V[172]*V[1]*V[244]*V[121]*V[102]*V[105]*V[16]+V[1]*V[245]*V[122]*V[101]*V[106]*V[173]*V[16])/(2)/(V[52]);
   if(!isfinite(V[345]) || FError) return 345;
   nCurrentVars=346;
   V[346]=1/(V[3])/(V[168])*M_SQRT2/(V[173])/(V[172])/(V[16])*(V[168]*V[172]*V[3]*V[248]*V[123]*V[104]*V[108]*V[173]-V[172]*V[1]*V[244]*V[121]*V[104]*V[107]*V[16]+V[1]*V[245]*V[122]*V[103]*V[108]*V[173]*V[16])/(2)/(V[53]);
   if(!isfinite(V[346]) || FError) return 346;
   nCurrentVars=347;
   V[347]=1/(V[3])/(V[168])*M_SQRT2/(V[173])/(V[172])/(V[16])*(V[168]*V[172]*V[3]*V[248]*V[126]*V[102]*V[106]*V[173]-V[172]*V[1]*V[244]*V[124]*V[102]*V[105]*V[16]+V[1]*V[245]*V[125]*V[101]*V[106]*V[173]*V[16])/(2)/(V[52]);
   if(!isfinite(V[347]) || FError) return 347;
   nCurrentVars=348;
   V[348]=1/(V[3])/(V[168])*M_SQRT2/(V[173])/(V[172])/(V[16])*(V[168]*V[172]*V[3]*V[248]*V[126]*V[104]*V[108]*V[173]-V[172]*V[1]*V[244]*V[124]*V[104]*V[107]*V[16]+V[1]*V[245]*V[125]*V[103]*V[108]*V[173]*V[16])/(2)/(V[53]);
   if(!isfinite(V[348]) || FError) return 348;
   nCurrentVars=349;
   V[349]=1/(V[3])/(V[168])*M_SQRT2/(V[173])/(V[172])/(V[16])*(V[168]*V[172]*V[3]*V[248]*V[129]*V[102]*V[106]*V[173]-V[172]*V[1]*V[244]*V[127]*V[102]*V[105]*V[16]+V[1]*V[245]*V[128]*V[101]*V[106]*V[173]*V[16])/(2)/(V[52]);
   if(!isfinite(V[349]) || FError) return 349;
   nCurrentVars=350;
   V[350]=1/(V[3])/(V[168])*M_SQRT2/(V[173])/(V[172])/(V[16])*(V[168]*V[172]*V[3]*V[248]*V[129]*V[104]*V[108]*V[173]-V[172]*V[1]*V[244]*V[127]*V[104]*V[107]*V[16]+V[1]*V[245]*V[128]*V[103]*V[108]*V[173]*V[16])/(2)/(V[53]);
   if(!isfinite(V[350]) || FError) return 350;
   nCurrentVars=351;
   V[351]=V[1]/(V[3])*V[211]*V[177]/(V[168])/(V[14])/(2)/(V[211])/(2);
   if(!isfinite(V[351]) || FError) return 351;
   nCurrentVars=352;
   V[352]=-V[1]/(V[3])*V[210]*V[177]/(V[168])/(V[173])/(V[172])*(V[179]-Pow(V[172],2))/(2)/(V[210])/(2);
   if(!isfinite(V[352]) || FError) return 352;
   nCurrentVars=353;
   V[353]=V[1]/(V[3])*V[209]*V[177]/(V[168])/(V[14])/(2)/(V[209])/(2);
   if(!isfinite(V[353]) || FError) return 353;
   nCurrentVars=354;
   V[354]=V[1]/(V[3])*V[8]*V[177]/(V[168])*V[14]/(2)/(V[8])/(2);
   if(!isfinite(V[354]) || FError) return 354;
   nCurrentVars=355;
   V[355]=V[1]/(V[3])*V[211]*V[178]/(V[168])/(V[14])/(2)/(V[211])/(2);
   if(!isfinite(V[355]) || FError) return 355;
   nCurrentVars=356;
   V[356]=-V[1]/(V[3])*V[210]*V[178]/(V[168])/(V[173])/(V[172])*(V[179]-Pow(V[172],2))/(2)/(V[210])/(2);
   if(!isfinite(V[356]) || FError) return 356;
   nCurrentVars=357;
   V[357]=V[1]/(V[3])*V[209]*V[178]/(V[168])/(V[14])/(2)/(V[209])/(2);
   if(!isfinite(V[357]) || FError) return 357;
   nCurrentVars=358;
   V[358]=V[1]/(V[3])*V[8]*V[178]/(V[168])*V[14]/(2)/(V[8])/(2);
   if(!isfinite(V[358]) || FError) return 358;
   nCurrentVars=359;
   V[359]=1/(V[3])/(V[168])*M_SQRT2/(V[173])/(V[172])/(V[16])*(Pow(V[173],2)*V[1]*V[245]*V[177]*V[101]*V[106]*V[16]-Pow(V[172],2)*V[1]*V[244]*V[177]*V[102]*V[105]*V[16]-V[168]*V[172]*V[3]*V[248]*V[175]*V[102]*V[106]*V[173])/(2)/(V[52])/(2);
   if(!isfinite(V[359]) || FError) return 359;
   nCurrentVars=360;
   V[360]=1/(V[3])/(V[168])*M_SQRT2/(V[173])/(V[172])/(V[16])*(Pow(V[173],2)*V[1]*V[245]*V[177]*V[103]*V[108]*V[16]-Pow(V[172],2)*V[1]*V[244]*V[177]*V[104]*V[107]*V[16]-V[168]*V[172]*V[3]*V[248]*V[175]*V[104]*V[108]*V[173])/(2)/(V[53])/(2);
   if(!isfinite(V[360]) || FError) return 360;
   nCurrentVars=361;
   V[361]=1/(V[3])/(V[168])*M_SQRT2/(V[173])/(V[172])/(V[16])*(Pow(V[173],2)*V[1]*V[245]*V[178]*V[101]*V[106]*V[16]-Pow(V[172],2)*V[1]*V[244]*V[178]*V[102]*V[105]*V[16]-V[168]*V[172]*V[3]*V[248]*V[176]*V[102]*V[106]*V[173])/(2)/(V[52])/(2);
   if(!isfinite(V[361]) || FError) return 361;
   nCurrentVars=362;
   V[362]=1/(V[3])/(V[168])*M_SQRT2/(V[173])/(V[172])/(V[16])*(Pow(V[173],2)*V[1]*V[245]*V[178]*V[103]*V[108]*V[16]-Pow(V[172],2)*V[1]*V[244]*V[178]*V[104]*V[107]*V[16]-V[168]*V[172]*V[3]*V[248]*V[176]*V[104]*V[108]*V[173])/(2)/(V[53])/(2);
   if(!isfinite(V[362]) || FError) return 362;
   nCurrentVars=363;
   V[363]=alphaQCD(V[41])/(V[255]);
   if(!isfinite(V[363]) || FError) return 363;
   nCurrentVars=364;
   V[364]=Sqrt(1+V[363]*(149/(double)((12))+V[363]*(68.6482-V[363]*212.447)));
   if(!isfinite(V[364]) || FError) return 364;
   nCurrentVars=365;
   V[365]=alphaQCD(V[42])/(V[255]);
   if(!isfinite(V[365]) || FError) return 365;
   nCurrentVars=366;
   V[366]=Sqrt(1+V[365]*(149/(double)((12))+V[365]*(68.6482-V[365]*212.447)));
   if(!isfinite(V[366]) || FError) return 366;
   nCurrentVars=367;
   V[367]=alphaQCD(V[43])/(V[255]);
   if(!isfinite(V[367]) || FError) return 367;
   nCurrentVars=368;
   V[368]=Sqrt(1+V[367]*(149/(double)((12))+V[367]*(68.6482-V[367]*212.447)));
   if(!isfinite(V[368]) || FError) return 368;
   nCurrentVars=369;
   V[369]=alphaQCD(V[44])/(V[255]);
   if(!isfinite(V[369]) || FError) return 369;
   nCurrentVars=370;
   V[370]=Sqrt(1+V[369]*(149/(double)((12))+V[369]*(68.6482-V[369]*212.447)));
   if(!isfinite(V[370]) || FError) return 370;
   nCurrentVars=371;
   V[371]=alphaQCD(V[45])/(V[255]);
   if(!isfinite(V[371]) || FError) return 371;
   nCurrentVars=372;
   V[372]=Sqrt(1+V[371]*(149/(double)((12))+V[371]*(68.6482-V[371]*212.447)));
   if(!isfinite(V[372]) || FError) return 372;
   nCurrentVars=373;
   V[373]=-Cabs(hGGeven(V[41],V[363],15,1,3,V[7],V[260],1,3,V[256],V[259],1,3,V[257],V[258],0,3,V[55],V[274],0,3,V[56],V[275],0,3,V[57],V[278],0,3,V[58],V[279],0,3,V[61],V[280],0,3,V[62],V[281],0,3,V[59],V[276],0,3,V[60],V[277],0,3,V[65],V[286],0,3,V[66],V[287],0,3,V[63],V[284],0,3,V[64],V[285]));
   if(!isfinite(V[373]) || FError) return 373;
   nCurrentVars=374;
   V[374]=-Cabs(hGGeven(V[42],V[365],15,1,3,V[7],V[264],1,3,V[256],V[263],1,3,V[257],V[262],0,3,V[55],V[292],0,3,V[56],V[293],0,3,V[57],V[296],0,3,V[58],V[297],0,3,V[61],V[298],0,3,V[62],V[299],0,3,V[59],V[294],0,3,V[60],V[295],0,3,V[65],V[304],0,3,V[66],V[305],0,3,V[63],V[302],0,3,V[64],V[303]));
   if(!isfinite(V[374]) || FError) return 374;
   nCurrentVars=375;
   V[375]=-Cabs(hGGeven(V[43],V[367],15,1,3,V[7],V[268],1,3,V[256],V[267],1,3,V[257],V[266],0,3,V[55],V[310],0,3,V[56],V[311],0,3,V[57],V[314],0,3,V[58],V[315],0,3,V[61],V[316],0,3,V[62],V[317],0,3,V[59],V[312],0,3,V[60],V[313],0,3,V[65],V[322],0,3,V[66],V[323],0,3,V[63],V[320],0,3,V[64],V[321]));
   if(!isfinite(V[375]) || FError) return 375;
   nCurrentVars=376;
   V[376]=4/(double)((9));
   if(!isfinite(V[376]) || FError) return 376;
   nCurrentVars=377;
   V[377]=1/(double)((9));
   if(!isfinite(V[377]) || FError) return 377;
   nCurrentVars=378;
   V[378]=-Cabs(V[376]*hAAeven(V[41],V[363],8,1,3,V[7],V[260],1,3,V[257],V[258],0,3,V[55],V[274],0,3,V[56],V[275],0,3,V[59],V[276],0,3,V[60],V[277],0,3,V[63],V[284],0,3,V[64],V[285])+V[377]*hAAeven(V[41],V[363],7,1,3,V[256],V[259],0,3,V[57],V[278],0,3,V[58],V[279],0,3,V[61],V[280],0,3,V[62],V[281],0,3,V[65],V[286],0,3,V[66],V[287])+hAAeven(V[41],V[363],11,2,1,V[3],V[324],1,1,V[52],V[345],1,1,V[53],V[346],0,1,V[46],V[330],0,1,V[67],V[270],0,1,V[68],V[271],0,1,V[69],V[272],0,1,V[70],V[273],0,1,V[71],V[282],0,1,V[72],V[283],1,1,V[8],V[261]));
   if(!isfinite(V[378]) || FError) return 378;
   nCurrentVars=379;
   V[379]=-Cabs(V[376]*hAAeven(V[42],V[365],8,1,3,V[7],V[264],1,3,V[257],V[262],0,3,V[55],V[292],0,3,V[56],V[293],0,3,V[59],V[294],0,3,V[60],V[295],0,3,V[63],V[302],0,3,V[64],V[303])+V[377]*hAAeven(V[42],V[365],7,1,3,V[256],V[263],0,3,V[57],V[296],0,3,V[58],V[297],0,3,V[61],V[298],0,3,V[62],V[299],0,3,V[65],V[304],0,3,V[66],V[305])+hAAeven(V[42],V[365],11,2,1,V[3],V[331],1,1,V[52],V[347],1,1,V[53],V[348],0,1,V[46],V[337],0,1,V[67],V[288],0,1,V[68],V[289],0,1,V[69],V[290],0,1,V[70],V[291],0,1,V[71],V[300],0,1,V[72],V[301],1,1,V[8],V[265]));
   if(!isfinite(V[379]) || FError) return 379;
   nCurrentVars=380;
   V[380]=-Cabs(V[376]*hAAeven(V[43],V[367],8,1,3,V[7],V[268],1,3,V[257],V[266],0,3,V[55],V[310],0,3,V[56],V[311],0,3,V[59],V[312],0,3,V[60],V[313],0,3,V[63],V[320],0,3,V[64],V[321])+V[377]*hAAeven(V[43],V[367],7,1,3,V[256],V[267],0,3,V[57],V[314],0,3,V[58],V[315],0,3,V[61],V[316],0,3,V[62],V[317],0,3,V[65],V[322],0,3,V[66],V[323])+hAAeven(V[43],V[367],11,2,1,V[3],V[338],1,1,V[52],V[349],1,1,V[53],V[350],0,1,V[46],V[344],0,1,V[67],V[306],0,1,V[68],V[307],0,1,V[69],V[308],0,1,V[70],V[309],0,1,V[71],V[318],0,1,V[72],V[319],1,1,V[8],V[269]));
   if(!isfinite(V[380]) || FError) return 380;
   nCurrentVars=381;
   V[381]=-Cabs(hGGodd(V[44],V[369],3,1,3,V[257],V[351],1,3,V[256],V[352],1,3,V[7],V[353]));
   if(!isfinite(V[381]) || FError) return 381;
   nCurrentVars=382;
   V[382]=-Cabs(hGGodd(V[45],V[371],3,1,3,V[257],V[355],1,3,V[256],V[356],1,3,V[7],V[357]));
   if(!isfinite(V[382]) || FError) return 382;
   nCurrentVars=383;
   V[383]=-Cabs(V[377]*hAAodd(V[44],V[369],1,1,3,V[256],V[352])+V[376]*hAAodd(V[44],V[369],2,1,3,V[7],V[353],1,3,V[257],V[351])+hAAodd(V[44],V[369],3,1,1,V[8],V[354],1,1,V[52],V[359],1,1,V[53],V[360]));
   if(!isfinite(V[383]) || FError) return 383;
   nCurrentVars=384;
   V[384]=-Cabs(V[377]*hAAodd(V[45],V[371],1,1,3,V[256],V[356])+V[376]*hAAodd(V[45],V[371],2,1,3,V[7],V[357],1,3,V[257],V[355])+hAAodd(V[45],V[371],3,1,1,V[8],V[358],1,1,V[52],V[361],1,1,V[53],V[362]));
   if(!isfinite(V[384]) || FError) return 384;
   nCurrentVars=385;
   V[385]=V[124]*V[173]+V[125]*V[172];
   if(!isfinite(V[385]) || FError) return 385;
   if(VV==NULL) 
   {  VV=malloc(sizeof(REAL)*nModelVars);
      for(i=0;i<nModelVars;i++) if(strcmp(varNames[i],"Q")==0) iQ=i;
   }
   for(i=0;i<nModelVars;i++) VV[i]=V[i];
   cErr=0;
   nCurrentVars++;
   return 0;
}
