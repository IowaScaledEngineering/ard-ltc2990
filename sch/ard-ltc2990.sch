v 20130925 2
T 67000 40900 9 10 1 0 0 0 1
LTC2990 Arduino Shield
T 66800 40600 9 10 1 0 0 0 1
ard-ltc2990.sch
T 67000 40300 9 10 1 0 0 0 1
1
T 68500 40300 9 10 1 0 0 0 1
1
T 70800 40300 9 10 1 0 0 0 1
Nathan D. Holmes
C 40000 40000 0 0 0 title-bordered-D.sym
C 60500 42400 1 0 0 hole-1.sym
{
T 60500 42400 5 10 0 1 0 0 1
device=HOLE
T 60700 43000 5 10 1 1 0 4 1
refdes=H1
T 60500 42400 5 10 0 0 0 0 1
footprint=ARDUINO_SHIELD_HOLE
}
C 61000 42400 1 0 0 hole-1.sym
{
T 61000 42400 5 10 0 1 0 0 1
device=HOLE
T 61200 43000 5 10 1 1 0 4 1
refdes=H2
T 61000 42400 5 10 0 0 0 0 1
footprint=ARDUINO_SHIELD_HOLE
}
C 61500 42400 1 0 0 hole-1.sym
{
T 61500 42400 5 10 0 1 0 0 1
device=HOLE
T 61700 43000 5 10 1 1 0 4 1
refdes=H3
T 61500 42400 5 10 0 0 0 0 1
footprint=ARDUINO_SHIELD_HOLE
}
C 62000 42400 1 0 0 hole-1.sym
{
T 62000 42400 5 10 0 1 0 0 1
device=HOLE
T 62200 43000 5 10 1 1 0 4 1
refdes=H4
T 62000 42400 5 10 0 0 0 0 1
footprint=ARDUINO_SHIELD_HOLE
}
C 65900 61200 1 180 0 arduino-left.sym
{
T 65900 59600 5 10 0 1 180 0 1
device=AVRPROG
T 63900 56400 5 10 1 1 0 0 1
refdes=J1
T 65900 61200 5 10 0 0 180 0 1
footprint=ARDUINO_LEFT
}
C 63100 44900 1 0 0 arduino-right.sym
{
T 63100 46500 5 10 0 1 0 0 1
device=AVRPROG
T 63900 48200 5 10 1 1 0 0 1
refdes=J2
T 63100 44900 5 10 0 0 0 0 1
footprint=ARDUINO_RIGHT
}
C 44200 48400 1 0 1 termblk2-1.sym
{
T 43200 49050 5 10 0 0 0 6 1
device=TERMBLK2
T 43900 49300 5 10 1 1 0 6 1
refdes=J3C
T 44200 48400 5 10 0 1 0 0 1
footprint=TERMBLK2_200MIL
}
N 44600 45000 48200 45000 4
N 44200 46800 48600 46800 4
C 44200 46200 1 0 1 termblk2-1.sym
{
T 43200 46850 5 10 0 0 0 6 1
device=TERMBLK2
T 43900 47100 5 10 1 1 0 6 1
refdes=J3D
T 44200 46200 5 10 0 1 0 0 1
footprint=TERMBLK2_200MIL
}
N 44600 45000 44600 46400 4
N 44600 46400 44200 46400 4
C 49400 48200 1 0 1 gnd-1.sym
N 48300 49000 48300 47600 4
N 48300 47600 48600 47600 4
N 48600 47200 44200 47200 4
N 44200 47200 44200 48600 4
N 48200 45000 48200 46400 4
N 48200 46400 48600 46400 4
N 49800 48300 49800 49400 4
C 49900 45000 1 0 1 gnd-1.sym
N 49800 45300 49800 45700 4
N 51000 46400 51600 46400 4
N 51000 46800 51300 46800 4
C 48600 45700 1 0 0 ltc2990.sym
{
T 49800 47000 5 10 1 1 0 4 1
device=LTC2990
T 50700 48050 5 10 1 1 0 6 1
refdes=U2
T 49700 45900 5 10 1 1 0 8 1
footprint=LTC_MS10
}
C 49500 49400 1 90 1 capacitor-1.sym
{
T 48800 49200 5 10 0 1 270 2 1
device=CAPACITOR
T 49200 49100 5 10 1 1 0 6 1
refdes=C2
T 48600 49200 5 10 0 0 270 2 1
symversion=0.1
T 49200 48600 5 10 1 1 0 6 1
value=0.1uF
T 49500 49400 5 10 0 0 0 6 1
footprint=0805
T 49200 48400 5 10 1 1 0 6 1
description=16V
}
C 45000 48100 1 270 0 capacitor-1.sym
{
T 45700 47900 5 10 0 1 270 0 1
device=CAPACITOR
T 45300 47800 5 10 1 1 0 0 1
refdes=C6C
T 45900 47900 5 10 0 0 270 0 1
symversion=0.1
T 45300 47300 5 10 1 1 0 0 1
value=470pF
T 45000 48100 5 10 0 0 0 0 1
footprint=0805
T 45900 47300 5 10 1 1 0 0 1
description=16V
}
C 45000 45900 1 270 0 capacitor-1.sym
{
T 45700 45700 5 10 0 1 270 0 1
device=CAPACITOR
T 45300 45600 5 10 1 1 0 0 1
refdes=C6D
T 45900 45700 5 10 0 0 270 0 1
symversion=0.1
T 45300 45100 5 10 1 1 0 0 1
value=470pF
T 45000 45900 5 10 0 0 0 0 1
footprint=0805
T 45900 45100 5 10 1 1 0 0 1
description=16V
}
T 43300 48900 9 10 1 0 0 6 1
D+
T 43300 48500 9 10 1 0 0 6 1
D-
T 43300 46700 9 10 1 0 0 6 1
D+
T 43300 46300 9 10 1 0 0 6 1
D-
N 48300 49000 44200 49000 4
N 49300 49400 49800 49400 4
N 45200 48300 45200 48100 4
N 45200 48700 45200 49000 4
C 44200 53500 1 0 1 termblk2-1.sym
{
T 43200 54150 5 10 0 0 0 6 1
device=TERMBLK2
T 43900 54400 5 10 1 1 0 6 1
refdes=J3A
T 44200 53500 5 10 0 1 0 0 1
footprint=TERMBLK2_200MIL
}
N 44600 50100 48200 50100 4
N 44200 51900 48600 51900 4
C 44200 51300 1 0 1 termblk2-1.sym
{
T 43200 51950 5 10 0 0 0 6 1
device=TERMBLK2
T 43900 52200 5 10 1 1 0 6 1
refdes=J3B
T 44200 51300 5 10 0 1 0 0 1
footprint=TERMBLK2_200MIL
}
N 44600 50100 44600 51500 4
N 44600 51500 44200 51500 4
C 49400 53300 1 0 1 gnd-1.sym
N 48300 54100 48300 52700 4
N 48300 52700 48600 52700 4
N 48600 52300 44200 52300 4
N 44200 52300 44200 53700 4
N 48200 50100 48200 51500 4
N 48200 51500 48600 51500 4
N 49800 53400 49800 54500 4
C 49900 50100 1 0 1 gnd-1.sym
N 49800 50400 49800 50800 4
N 51000 51500 51600 51500 4
N 51600 44700 51600 51500 4
N 51000 51900 51300 51900 4
C 48600 50800 1 0 0 ltc2990.sym
{
T 49800 52100 5 10 1 1 0 4 1
device=LTC2990
T 50700 53150 5 10 1 1 0 6 1
refdes=U1
T 49700 51000 5 10 1 1 0 8 1
footprint=LTC_MS10
}
C 49500 54500 1 90 1 capacitor-1.sym
{
T 48800 54300 5 10 0 1 270 2 1
device=CAPACITOR
T 49200 54200 5 10 1 1 0 6 1
refdes=C1
T 48600 54300 5 10 0 0 270 2 1
symversion=0.1
T 49200 53700 5 10 1 1 0 6 1
value=0.1uF
T 49500 54500 5 10 0 0 0 6 1
footprint=0805
T 49200 53500 5 10 1 1 0 6 1
description=16V
}
C 45000 53200 1 270 0 capacitor-1.sym
{
T 45700 53000 5 10 0 1 270 0 1
device=CAPACITOR
T 45300 52900 5 10 1 1 0 0 1
refdes=C6A
T 45900 53000 5 10 0 0 270 0 1
symversion=0.1
T 45300 52400 5 10 1 1 0 0 1
value=470pF
T 45000 53200 5 10 0 0 0 0 1
footprint=0805
T 45900 52400 5 10 1 1 0 0 1
description=16V
}
C 45000 51000 1 270 0 capacitor-1.sym
{
T 45700 50800 5 10 0 1 270 0 1
device=CAPACITOR
T 45300 50700 5 10 1 1 0 0 1
refdes=C6B
T 45900 50800 5 10 0 0 270 0 1
symversion=0.1
T 45300 50200 5 10 1 1 0 0 1
value=470pF
T 45000 51000 5 10 0 0 0 0 1
footprint=0805
T 45900 50200 5 10 1 1 0 0 1
description=16V
}
N 48300 54100 44200 54100 4
N 49300 54500 49800 54500 4
N 45200 53400 45200 53200 4
N 45200 53800 45200 54100 4
T 43300 54000 9 10 1 0 0 6 1
D+
T 43300 53600 9 10 1 0 0 6 1
D-
T 43300 51800 9 10 1 0 0 6 1
D+
T 43300 51400 9 10 1 0 0 6 1
D-
N 49800 50600 51300 50600 4
N 51300 50600 51300 51900 4
N 51300 46800 51300 48700 4
N 51300 48700 49800 48700 4
N 51000 47300 54200 47300 4
N 54200 45400 54200 53600 4
N 54200 52400 51000 52400 4
N 51000 47600 53900 47600 4
N 53900 46300 53900 54800 4
N 51000 52700 53900 52700 4
T 51900 43500 9 10 1 0 0 8 3
J11 - Address Jumper
On = U1/0x98, U2/0x9A, U3/0xA0
Off = U1/0x9C, U2/0x9E, U3/0xA2
C 56600 49900 1 0 1 gnd-1.sym
N 56500 50300 56500 50200 4
N 54200 51300 55700 51300 4
N 55700 51000 53900 51000 4
N 56500 50300 57300 50300 4
N 57300 50300 57300 51000 4
N 57300 51300 57600 51300 4
N 57600 49100 57600 51300 4
N 57600 49100 51600 49100 4
C 58600 52800 1 90 1 capacitor-1.sym
{
T 57900 52600 5 10 0 1 270 2 1
device=CAPACITOR
T 58300 52500 5 10 1 1 0 6 1
refdes=C3
T 57700 52600 5 10 0 0 270 2 1
symversion=0.1
T 58300 52000 5 10 1 1 0 6 1
value=0.1uF
T 58600 52800 5 10 0 0 0 6 1
footprint=0805
T 58300 51800 5 10 1 1 0 6 1
description=16V
}
C 58500 51500 1 0 1 gnd-1.sym
N 56500 52000 56500 52800 4
N 56500 52800 58400 52800 4
C 49600 54500 1 0 0 5V-plus-1.sym
C 56300 52800 1 0 0 5V-plus-1.sym
C 49600 49400 1 0 0 5V-plus-1.sym
C 61300 54900 1 0 0 5V-plus-1.sym
N 58400 51900 58400 51800 4
C 62300 54800 1 90 1 capacitor-1.sym
{
T 61600 54600 5 10 0 1 270 2 1
device=CAPACITOR
T 62000 54500 5 10 1 1 0 6 1
refdes=C4
T 61400 54600 5 10 0 0 270 2 1
symversion=0.1
T 62600 54000 5 10 1 1 0 6 1
value=10uF
T 62300 54800 5 10 0 0 0 6 1
footprint=0805
T 62500 54500 5 10 1 1 0 6 1
description=16V
}
N 61500 53700 63500 53700 4
C 58600 54200 1 0 0 header3x2-1.sym
{
T 58600 55800 5 10 0 1 0 0 1
device=header3x2-1
T 59200 55500 5 10 1 1 0 0 1
refdes=JP6
T 58600 54200 5 10 0 0 0 0 1
footprint=JUMPER3x2-SMT
}
N 53600 54800 58600 54800 4
N 53600 53600 60200 53600 4
N 60200 53600 60200 54800 4
N 60000 54800 60200 54800 4
N 60000 54400 61000 54400 4
N 61000 54400 61000 52200 4
N 61000 52200 63500 52200 4
N 63500 51800 60600 51800 4
N 60600 51800 60600 53900 4
N 60600 53900 58600 53900 4
N 58600 53900 58600 54400 4
N 58600 55200 58600 58400 4
N 58600 58400 63500 58400 4
N 60000 55200 60200 55200 4
N 60200 55200 60200 58800 4
N 60200 58800 63500 58800 4
C 58600 45100 1 0 1 modular_6p6c_small.sym
{
T 58400 44800 5 10 1 1 0 6 1
refdes=J5
T 58600 49125 5 10 0 0 0 6 1
footprint=modular_6p6c_lp
T 57900 44800 5 10 1 1 0 6 1
device=RJ11 / 6p6c
}
N 56200 45400 54200 45400 4
N 56200 46300 53900 46300 4
C 52600 44600 1 0 1 gnd-1.sym
N 61000 55700 63500 55700 4
N 62600 44000 62600 47100 4
N 62600 47100 63500 47100 4
N 55600 45700 55600 43600 4
N 62900 43600 62900 46700 4
N 62900 46700 63500 46700 4
N 63500 46300 63200 46300 4
N 63200 43200 63200 46300 4
C 57600 43000 1 0 0 header3x2-1.sym
{
T 57600 44600 5 10 0 1 0 0 1
device=header3x2-1
T 58200 44300 5 10 1 1 0 0 1
refdes=JP10
T 57600 43000 5 10 0 0 0 0 1
footprint=JUMPER3x2-SMT
}
N 54500 44000 57600 44000 4
N 55500 43600 57600 43600 4
N 54500 43200 57600 43200 4
C 53200 44300 1 0 0 5V-plus-1.sym
N 63200 43200 59000 43200 4
N 59000 43600 62900 43600 4
N 62600 44000 59000 44000 4
T 58300 42800 9 10 1 0 0 5 4
Jumper:
1-2 - /IRQ on D3 
3-4 - /RESET on D4
5-6 - /OEN on D5
N 53400 43200 53600 43200 4
T 55900 55100 9 10 1 0 0 0 3
JP6 - Arduino I2C Pins
Older Arduinos use A4/A5
Newer Arduinos use SDA/SCL
T 53800 55400 9 10 1 0 0 6 1
I2C Pullup Enable
C 46000 43400 1 0 1 termblk2-1.sym
{
T 45000 44050 5 10 0 0 0 6 1
device=TERMBLK2
T 45700 44300 5 10 1 1 0 6 1
refdes=J4
T 46000 43400 5 10 0 1 0 0 1
footprint=TERMBLK2_200MIL
}
C 46500 43200 1 0 1 gnd-1.sym
C 46200 44100 1 0 0 5V-plus-1.sym
N 46000 44000 46400 44000 4
N 45200 46500 45200 46800 4
N 45200 45900 45200 46100 4
N 45200 51600 45200 51900 4
N 45200 51000 45200 51200 4
C 51900 46200 1 0 0 5V-plus-1.sym
N 52100 46200 52100 46100 4
N 51400 44700 52100 44700 4
N 52100 44700 52100 45200 4
C 55300 45700 1 0 1 gnd-1.sym
N 55200 46000 56200 46000 4
N 55600 45700 56200 45700 4
N 55900 46600 55900 43200 4
N 56200 44000 56200 45100 4
N 53400 43200 53400 44300 4
N 53400 43600 54600 43600 4
N 53400 44000 53600 44000 4
N 55900 46600 56200 46600 4
C 47000 52400 1 0 0 header4-1.sym
{
T 48000 53050 5 10 0 0 0 0 1
device=HEADER3
T 47500 54200 5 10 1 1 0 3 1
refdes=JP4AB
T 47000 52400 5 10 0 0 0 6 1
footprint=JUMPER4-SMT
}
N 45200 53800 47000 53800 4
N 47000 53400 45200 53400 4
N 45200 51600 46500 51600 4
N 46500 51600 46500 53000 4
N 46500 53000 47000 53000 4
N 47000 52600 46800 52600 4
N 46800 52600 46800 51200 4
N 46800 51200 45200 51200 4
C 47000 47300 1 0 0 header4-1.sym
{
T 48000 47950 5 10 0 0 0 0 1
device=HEADER3
T 47500 49100 5 10 1 1 0 3 1
refdes=JP4CD
T 47000 47300 5 10 0 0 0 6 1
footprint=JUMPER4-SMT
}
N 45200 48700 47000 48700 4
N 47000 48300 45200 48300 4
N 46500 47900 47000 47900 4
N 46500 46500 46500 47900 4
N 47000 47500 46800 47500 4
N 46800 47500 46800 46100 4
N 45200 46500 46500 46500 4
N 46800 46100 45200 46100 4
N 54300 54400 54300 56400 4
N 54700 54000 54700 56400 4
N 54300 57500 54700 57500 4
N 54300 57300 54300 57500 4
N 54700 57300 54700 57500 4
C 54300 57600 1 0 0 5V-plus-1.sym
N 54500 57600 54500 57500 4
C 53600 53400 1 0 1 header4-1.sym
{
T 52600 54050 5 10 0 0 0 6 1
device=HEADER3
T 53600 53400 5 10 0 0 0 0 1
footprint=JUMPER4-SMT
T 53100 55100 5 10 1 1 0 3 1
refdes=JP5
}
N 54300 54400 53600 54400 4
N 54700 54000 53600 54000 4
C 54200 57700 1 270 0 res-pack2-1.sym
{
T 54200 57700 5 10 0 0 0 0 1
slot=2
T 54100 56800 5 10 1 1 0 7 1
value=2k
T 54100 57000 5 10 1 1 0 7 1
refdes=R1
T 54100 56600 5 10 1 1 0 7 1
footprint=RPACK2-0606
}
C 54800 57700 1 90 1 res-pack2-1.sym
{
T 54800 57700 5 10 0 0 0 6 1
slot=1
T 54900 56800 5 10 1 1 0 1 1
value=2k
T 54900 57000 5 10 1 1 0 1 1
refdes=R1
T 54900 56600 5 10 1 1 0 1 1
footprint=RPACK2-0606
}
C 55700 49400 1 0 0 24AA025E48-1.sym
{
T 55700 51900 5 10 1 1 0 4 1
device=24AA025E48
T 56200 52050 5 10 1 1 0 6 1
refdes=U3
T 55700 49400 5 10 0 0 0 0 1
footprint=SOT26
}
C 53200 44100 1 180 1 res-pack4-1.sym
{
T 53200 44100 5 10 0 0 90 6 1
slot=1
T 54100 44150 5 10 1 1 180 8 1
value=10k
T 54000 44150 5 10 1 1 180 2 1
refdes=R2
T 54700 43700 5 10 0 1 180 1 1
footprint=RPACK4-1206
}
C 54200 43700 1 180 1 res-pack4-1.sym
{
T 54200 43700 5 10 0 0 90 6 1
slot=2
T 55100 43750 5 10 1 1 180 8 1
value=10k
T 55000 43750 5 10 1 1 180 2 1
refdes=R2
T 55700 43300 5 10 0 1 180 1 1
footprint=RPACK4-1206
}
C 53200 43300 1 180 1 res-pack4-1.sym
{
T 53200 43300 5 10 0 0 90 6 1
slot=3
T 54100 43350 5 10 1 1 180 8 1
value=10k
T 54000 43350 5 10 1 1 180 2 1
refdes=R2
T 54700 42900 5 10 0 1 180 1 1
footprint=RPACK4-1206
}
C 52200 46500 1 90 1 res-pack4-1.sym
{
T 52200 46500 5 10 0 0 0 6 1
slot=4
T 52250 45600 5 10 1 1 90 8 1
value=10k
T 52250 45700 5 10 1 1 90 2 1
refdes=R2
T 51800 45000 5 10 0 1 90 1 1
footprint=RPACK4-1206
}
N 46400 43500 46400 43600 4
N 46400 43600 46000 43600 4
N 46400 44000 46400 44100 4
C 51400 43700 1 0 1 header4-1.sym
{
T 50400 44350 5 10 0 0 0 6 1
device=HEADER3
T 51400 43700 5 10 0 0 0 0 1
footprint=JUMPER4-SMT
T 50900 45400 5 10 1 1 0 3 1
refdes=JP7
}
N 61500 53700 61500 54900 4
N 62100 53900 62100 53700 4
N 62100 54800 62100 55700 4
C 61100 55200 1 0 1 gnd-1.sym
N 61000 55500 61000 55700 4
N 63500 55300 63300 55300 4
N 63300 55300 63300 55700 4
N 63200 53700 63200 52900 4
N 63500 54900 62900 54900 4
N 62900 54900 62900 52700 4
N 62900 52700 65100 52700 4
N 51400 44300 52500 44300 4
N 52500 44300 52500 41400 4
N 52500 41400 65100 41400 4
N 65100 41400 65100 52700 4
N 63200 52900 65400 52900 4
N 65400 52900 65400 41100 4
N 52200 41100 65400 41100 4
N 52200 41100 52200 43900 4
N 52200 43900 51400 43900 4
N 51400 45100 52500 45100 4
N 52500 45100 52500 44900 4
