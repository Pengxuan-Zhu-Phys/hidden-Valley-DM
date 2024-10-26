# This file was automatically created by FeynRules 2.3.49
# Mathematica version: 8.0 for Linux x86 (64-bit) (October 10, 2011)
# Date: Wed 28 Aug 2024 09:04:05



from object_library import all_parameters, Parameter


from function_library import complexconjugate, re, im, csc, sec, acsc, asec, cot

# This is a default parameter object representing 0.
ZERO = Parameter(name = 'ZERO',
                 nature = 'internal',
                 type = 'real',
                 value = '0.0',
                 texname = '0')

# User-defined parameters.
cabi = Parameter(name = 'cabi',
                 nature = 'external',
                 type = 'real',
                 value = 0.227736,
                 texname = '\\theta _c',
                 lhablock = 'CKMBLOCK',
                 lhacode = [ 1 ])

gVXd = Parameter(name = 'gVXd',
                 nature = 'external',
                 type = 'real',
                 value = 1.,
                 texname = 'g_{\\text{VXd}}',
                 lhablock = 'DMINPUTS',
                 lhacode = [ 1 ])

gAXd = Parameter(name = 'gAXd',
                 nature = 'external',
                 type = 'real',
                 value = 0.,
                 texname = 'g_{\\text{AXd}}',
                 lhablock = 'DMINPUTS',
                 lhacode = [ 2 ])

gVl11 = Parameter(name = 'gVl11',
                  nature = 'external',
                  type = 'real',
                  value = 0.,
                  texname = 'g_{\\text{Ve}}',
                  lhablock = 'DMINPUTS',
                  lhacode = [ 3 ])

gVl22 = Parameter(name = 'gVl22',
                  nature = 'external',
                  type = 'real',
                  value = 0.,
                  texname = 'g_{\\text{Vmu}}',
                  lhablock = 'DMINPUTS',
                  lhacode = [ 4 ])

gVl33 = Parameter(name = 'gVl33',
                  nature = 'external',
                  type = 'real',
                  value = 0.,
                  texname = 'g_{\\text{Vta}}',
                  lhablock = 'DMINPUTS',
                  lhacode = [ 5 ])

gAl11 = Parameter(name = 'gAl11',
                  nature = 'external',
                  type = 'real',
                  value = 0.,
                  texname = 'g_{\\text{Ae}}',
                  lhablock = 'DMINPUTS',
                  lhacode = [ 6 ])

gAl22 = Parameter(name = 'gAl22',
                  nature = 'external',
                  type = 'real',
                  value = 0.,
                  texname = 'g_{\\text{Amu}}',
                  lhablock = 'DMINPUTS',
                  lhacode = [ 7 ])

gAl33 = Parameter(name = 'gAl33',
                  nature = 'external',
                  type = 'real',
                  value = 0.,
                  texname = 'g_{\\text{Ata}}',
                  lhablock = 'DMINPUTS',
                  lhacode = [ 8 ])

gnu11 = Parameter(name = 'gnu11',
                  nature = 'external',
                  type = 'real',
                  value = 0.,
                  texname = 'g_{\\text{nue}}',
                  lhablock = 'DMINPUTS',
                  lhacode = [ 9 ])

gnu22 = Parameter(name = 'gnu22',
                  nature = 'external',
                  type = 'real',
                  value = 0.,
                  texname = 'g_{\\text{num}}',
                  lhablock = 'DMINPUTS',
                  lhacode = [ 10 ])

gnu33 = Parameter(name = 'gnu33',
                  nature = 'external',
                  type = 'real',
                  value = 0.,
                  texname = 'g_{\\text{nut}}',
                  lhablock = 'DMINPUTS',
                  lhacode = [ 11 ])

gVh = Parameter(name = 'gVh',
                nature = 'external',
                type = 'real',
                value = 0.,
                texname = 'g_{\\text{Vh}}',
                lhablock = 'DMINPUTS',
                lhacode = [ 12 ])

aEWM1 = Parameter(name = 'aEWM1',
                  nature = 'external',
                  type = 'real',
                  value = 127.9,
                  texname = '\\text{aEWM1}',
                  lhablock = 'SMINPUTS',
                  lhacode = [ 1 ])

Gf = Parameter(name = 'Gf',
               nature = 'external',
               type = 'real',
               value = 0.0000116637,
               texname = 'G_f',
               lhablock = 'SMINPUTS',
               lhacode = [ 2 ])

aS = Parameter(name = 'aS',
               nature = 'external',
               type = 'real',
               value = 0.1184,
               texname = '\\alpha _s',
               lhablock = 'SMINPUTS',
               lhacode = [ 3 ])

ymt = Parameter(name = 'ymt',
                nature = 'external',
                type = 'real',
                value = 172,
                texname = '\\text{ymt}',
                lhablock = 'YUKAWA',
                lhacode = [ 6 ])

ymtau = Parameter(name = 'ymtau',
                  nature = 'external',
                  type = 'real',
                  value = 1.777,
                  texname = '\\text{ymtau}',
                  lhablock = 'YUKAWA',
                  lhacode = [ 15 ])

MZ = Parameter(name = 'MZ',
               nature = 'external',
               type = 'real',
               value = 91.1876,
               texname = '\\text{MZ}',
               lhablock = 'MASS',
               lhacode = [ 23 ])

MTA = Parameter(name = 'MTA',
                nature = 'external',
                type = 'real',
                value = 1.777,
                texname = '\\text{MTA}',
                lhablock = 'MASS',
                lhacode = [ 15 ])

MT = Parameter(name = 'MT',
               nature = 'external',
               type = 'real',
               value = 172,
               texname = '\\text{MT}',
               lhablock = 'MASS',
               lhacode = [ 6 ])

MH = Parameter(name = 'MH',
               nature = 'external',
               type = 'real',
               value = 125,
               texname = '\\text{MH}',
               lhablock = 'MASS',
               lhacode = [ 25 ])

MXd = Parameter(name = 'MXd',
                nature = 'external',
                type = 'real',
                value = 10.,
                texname = '\\text{MXd}',
                lhablock = 'MASS',
                lhacode = [ 5000521 ])

MY1 = Parameter(name = 'MY1',
                nature = 'external',
                type = 'real',
                value = 1000.,
                texname = '\\text{MY1}',
                lhablock = 'MASS',
                lhacode = [ 5000001 ])

WZ = Parameter(name = 'WZ',
               nature = 'external',
               type = 'real',
               value = 2.4952,
               texname = '\\text{WZ}',
               lhablock = 'DECAY',
               lhacode = [ 23 ])

WW = Parameter(name = 'WW',
               nature = 'external',
               type = 'real',
               value = 2.085,
               texname = '\\text{WW}',
               lhablock = 'DECAY',
               lhacode = [ 24 ])

WT = Parameter(name = 'WT',
               nature = 'external',
               type = 'real',
               value = 1.50833649,
               texname = '\\text{WT}',
               lhablock = 'DECAY',
               lhacode = [ 6 ])

WH = Parameter(name = 'WH',
               nature = 'external',
               type = 'real',
               value = 0.00407,
               texname = '\\text{WH}',
               lhablock = 'DECAY',
               lhacode = [ 25 ])

WY1 = Parameter(name = 'WY1',
                nature = 'external',
                type = 'real',
                value = 10.,
                texname = '\\text{WY1}',
                lhablock = 'DECAY',
                lhacode = [ 5000001 ])

CKM1x1 = Parameter(name = 'CKM1x1',
                   nature = 'internal',
                   type = 'complex',
                   value = 'cmath.cos(cabi)',
                   texname = '\\text{CKM1x1}')

CKM1x2 = Parameter(name = 'CKM1x2',
                   nature = 'internal',
                   type = 'complex',
                   value = 'cmath.sin(cabi)',
                   texname = '\\text{CKM1x2}')

CKM2x1 = Parameter(name = 'CKM2x1',
                   nature = 'internal',
                   type = 'complex',
                   value = '-cmath.sin(cabi)',
                   texname = '\\text{CKM2x1}')

CKM2x2 = Parameter(name = 'CKM2x2',
                   nature = 'internal',
                   type = 'complex',
                   value = 'cmath.cos(cabi)',
                   texname = '\\text{CKM2x2}')

aEW = Parameter(name = 'aEW',
                nature = 'internal',
                type = 'real',
                value = '1/aEWM1',
                texname = '\\alpha _{\\text{EW}}')

G = Parameter(name = 'G',
              nature = 'internal',
              type = 'real',
              value = '2*cmath.sqrt(aS)*cmath.sqrt(cmath.pi)',
              texname = 'G')

MW = Parameter(name = 'MW',
               nature = 'internal',
               type = 'real',
               value = 'cmath.sqrt(MZ**2/2. + cmath.sqrt(MZ**4/4. - (aEW*cmath.pi*MZ**2)/(Gf*cmath.sqrt(2))))',
               texname = 'M_W')

ee = Parameter(name = 'ee',
               nature = 'internal',
               type = 'real',
               value = '2*cmath.sqrt(aEW)*cmath.sqrt(cmath.pi)',
               texname = 'e')

sw2 = Parameter(name = 'sw2',
                nature = 'internal',
                type = 'real',
                value = '1 - MW**2/MZ**2',
                texname = '\\text{sw2}')

cw = Parameter(name = 'cw',
               nature = 'internal',
               type = 'real',
               value = 'cmath.sqrt(1 - sw2)',
               texname = 'c_w')

sw = Parameter(name = 'sw',
               nature = 'internal',
               type = 'real',
               value = 'cmath.sqrt(sw2)',
               texname = 's_w')

g1 = Parameter(name = 'g1',
               nature = 'internal',
               type = 'real',
               value = 'ee/cw',
               texname = 'g_1')

gw = Parameter(name = 'gw',
               nature = 'internal',
               type = 'real',
               value = 'ee/sw',
               texname = 'g_w')

vev = Parameter(name = 'vev',
                nature = 'internal',
                type = 'real',
                value = '(2*MW*sw)/ee',
                texname = '\\text{vev}')

lam = Parameter(name = 'lam',
                nature = 'internal',
                type = 'real',
                value = 'MH**2/(2.*vev**2)',
                texname = '\\text{lam}')

yt = Parameter(name = 'yt',
               nature = 'internal',
               type = 'real',
               value = '(ymt*cmath.sqrt(2))/vev',
               texname = '\\text{yt}')

ytau = Parameter(name = 'ytau',
                 nature = 'internal',
                 type = 'real',
                 value = '(ymtau*cmath.sqrt(2))/vev',
                 texname = '\\text{ytau}')

muH = Parameter(name = 'muH',
                nature = 'internal',
                type = 'real',
                value = 'cmath.sqrt(lam*vev**2)',
                texname = '\\mu')

