//
//  ExpertSystem.cpp
//  ExpertSystemProject
//
//  Created by Tyler Lawhorn on 6/21/21.
//

/* ****************************************************************************
 *            *
 *            *
 *            *
 *            *
 *            *
 *            *
 *            *
 *************************************************************************** */

#include <string>
#include <iostream>

using namespace std;

void search(string*,string*,int&,int&,int&,int&);

void check_instantiation(string&,string*,int*,string&,
                         string&,string&,string&,string&,
                         string&,string&,string&,string&,
                         string&,string&,string&,string&,
                         string&,string&,string&,string&,
                         string&,string&,string&);

void instantiate(string&,string*,string*,int*,int&);

void determine_member_concl_list(int&,int&,int&,string&, string*);
void push_on_stack(int&,int*,int&,int*);
void instantiate(string&, string*,int&, int*,string&, string&, string&, string&,
                 string&, string&, string&, string&, string&, string&, string&,
                  string&, string&, string&, string&, string&, string&, string&,
                 string&, string&, string&, string&, string& );

int main()
{
string conclutionQueue[5],
       variableLst[] = {"","batteryIssue","alternatorIssue","starterMotorIssue",
                        "pedalIssue","speakerIssue","doorIssue","strWhIssue",
                        "fuleInjIssue","fulePumpIssue","fuleFtrIssue","gasTankEmIssue",
                        "sensorIssue","waterPumpIssue","serpBltIssue","ignCoIssue",
                        "distCapIssue","alignmentIssue","airConIssue","gearIssue",
                        "brkIssue","battery","battRepair","alternator","altRepair",
                        "starterMotor","stMoRepair","pedal","pedalRepair","speaker",
                        "speakerRepair","door","doorRepair","strWh","strWhRepair",
                        "fuleInj", "fuleInjRepair","fulePump", "fulePumpRepair",
                        "fuleFtr", "fuleFtrRepair","gasTankEm", "gasTankEmRepair",
                        "sensor", "sensorRepair","waterPump", "waterPumpRepair",
                        "serpBlt", "serpBltRepair","ignCo", "ignCoRepair",
                        "distCap", "distCapRepair","alignment", "alignmentRepair",
                        "airCon", "airConRepair","gear", "gearRepair","brk",
                        "brkRepair",""},
      clauseVariableLst[321],
      conditionVariable,variable,
      batteryIssue, battery2, battRepair,
      alternatorIssue, alternator2, altRepair,
      starterMotorIssue, starterMotor2, stMoRepair,
      pedalIssue, pedal2, pedalRepair,
      speakerIssue, speaker2, speakerRepair,
      doorIssue, door2, doorRepair,
      strWhIssue, strWh2, strWhRepair,
      fuleInjIssue, fuleInj2, fuleInjRepair,
      fulePumpIssue, fulePump2, fulePumpRepair,
      fuleFtrIssue, fuleFtr2, fuleFtrRepair,
      gasTankEmIssue, gasTankEm2, gasTankEmRepair,
      sensorIssue, sensor2, sensorRepair,
      waterPumpIssue, waterPump2, waterPumpRepair,
      serpBltIssue, serpBlt2, serpBltRepair,
      ignCoIssue, ignCo2, ignCoRepair,
      distCapIssue, distCap2, distCapRepair,
      alignmentIssue, alignment2, alignmentRepair,
      airConIssue, airCon2, airConRepair,
      gearIssue, gear2, gearRepair,
      brkIssue, brk2, brkRepair;
               
   int frontPtr = 1,                   // front pointer for the conclution queue
       k2,                              // Holds the value for the KEY
       firstStm,                       // Holds the first statement
       statmentNum,                    // Holds the statement number
       clauseNum,                      // Holds the clause number
       backPtr = 1,                    // back pointer for the conclution queue
       setVal,
       repairCode = 0,//
       instlt2[62];
   
   for(int i = 0; i < 62; i++)
      instlt2[i] = 0;
   
   for(int i = 0; i < 321; i++)
      clauseVariableLst[i] = "";
  
   clauseVariableLst[1] = "battery";
   clauseVariableLst[5] = "battery";
   clauseVariableLst[9] = "batteryIssue";
   clauseVariableLst[13] = "batteryIssue";
   
   clauseVariableLst[17] = "alternator";
   clauseVariableLst[21] = "alternator";
   clauseVariableLst[25] = "alternatorIssue";
   clauseVariableLst[29] = "alternatorIssue";
   
   clauseVariableLst[33] = "starterMotor";
   clauseVariableLst[37] = "starterMotor";
   clauseVariableLst[41] = "starterMotorIssue";
   clauseVariableLst[45] = "starterMotorIssue";
 
   clauseVariableLst[49] = "pedal";
   clauseVariableLst[53] = "pedal";
   clauseVariableLst[57] = "pedalIssue";
   clauseVariableLst[61] = "pedalIssue";
   
   clauseVariableLst[65] = "speaker";
   clauseVariableLst[69] = "speaker";
   clauseVariableLst[73] = "speakerIssue";
   clauseVariableLst[77] = "speakerIssue";
   
   clauseVariableLst[81] = "door";
   clauseVariableLst[85] = "door";
   clauseVariableLst[89] = "doorIssue";
   clauseVariableLst[93] = "doorIssue";
   
   clauseVariableLst[97] = "strWh";
   clauseVariableLst[101] = "strWh";
   clauseVariableLst[105] = "strWhIssue";
   clauseVariableLst[109] = "strWhIssue";
   
   clauseVariableLst[113] = "fuleInj";
   clauseVariableLst[117] = "fuleInj";
   clauseVariableLst[121] = "fuleInjIssue";
   clauseVariableLst[125] = "fuleInjIssue";
   
   clauseVariableLst[129] = "fulePump";
   clauseVariableLst[133] = "fulePump";
   clauseVariableLst[137] = "fulePumpIssue";
   clauseVariableLst[141] = "fulePumpIssue";
   
   clauseVariableLst[145] = "fuleFtr";
   clauseVariableLst[149] = "fuleFtr";
   clauseVariableLst[153] = "fuleFtrIssue";
   clauseVariableLst[157] = "fuleFtrIssue";
   
   clauseVariableLst[161] = "gasTankEm";
   clauseVariableLst[165] = "gasTankEm";
   clauseVariableLst[169] = "gasTankEmIssue";
   clauseVariableLst[173] = "gasTankEmIssue";
   
   clauseVariableLst[177] = "sensor";
   clauseVariableLst[181] = "sensor";
   clauseVariableLst[185] = "sensorIssue";
   clauseVariableLst[189] = "sensorIssue";
   
   clauseVariableLst[193] = "waterPump";
   clauseVariableLst[197] = "waterPump";
   clauseVariableLst[201] = "waterPumpIssue";
   clauseVariableLst[205] = "waterPumpIssue";
   
   clauseVariableLst[209] = "serpBlt";
   clauseVariableLst[213] = "serpBlt";
   clauseVariableLst[217] = "serpBltIssue";
   clauseVariableLst[221] = "serpBltIssue";
   
   clauseVariableLst[225] = "ignCo";
   clauseVariableLst[229] = "ignCo";
   clauseVariableLst[233] = "ignCoIssue";
   clauseVariableLst[237] = "ignCoIssue";
   
   clauseVariableLst[241] = "distCap";
   clauseVariableLst[245] = "distCap";
   clauseVariableLst[249] = "distCapIssue";
   clauseVariableLst[253] = "distCapIssue";
   
   clauseVariableLst[257] = "alignment";
   clauseVariableLst[261] = "alighment";
   clauseVariableLst[265] = "alignmentIssue";;
   clauseVariableLst[269] = "alignmentIssue";
   
   clauseVariableLst[273] = "airCon";
   clauseVariableLst[277] = "airCon";
   clauseVariableLst[281] = "airConIssue";
   clauseVariableLst[285] = "airConIssue";

   clauseVariableLst[289] = "gear";
   clauseVariableLst[293] = "gear";
   clauseVariableLst[297] = "gearIssue";
   clauseVariableLst[301] = "gearIssue";
   
   clauseVariableLst[305] = "brk";
   clauseVariableLst[309] = "brk";
   clauseVariableLst[313] = "brkIssue";
   clauseVariableLst[317] = "brkIssue";
/* <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><> */
      


    string conclt[] = {"", "ISSUE", "BROKE", "INT", "EXT",
                      "BATTERY/ALTERNATOR-ISSUE", "BATTERY/ALTERNATOR-ISSUE",
                      "ENGINE-ISSUE","ENGINE-ISSUE","ENGINE-ISSUE",
                      "ENGINE-ISSUE","ENGINE-ISSUE","ENGINE-ISSUE",
                      "ENGINE-ISSUE","INTERIOR", "UNDRHOOD","OTHER-ISSUE",
                      "OTHER-ISSUE","OTHER-ISSUE","OTHER-ISSUE","CARRUN-ISSUE",
                      "CARRUN-ISSUE","CARRUN-ISSUE","CARRUN-ISSUE",
                      "INTERIOR-ISSUE","INTERIOR-ISSUE","INTERIOR-ISSUE",
                      "INTERIOR-ISSUE","INTERIOR-ISSUE","INTERIOR-ISSUE",
                      "INTERIOR-ISSUE","INTERIOR-ISSUE"};



    string varlt [] = {"","CARISSUE","CARSTART","BATTERY","ALT","STARTMTR",
                        "IGNCOIL","DISTCAP","GASTANK","FUELFILT","FUELPUMP",
                        "STAYRUN","OVERHEAT","COOLENT","SERPBELT","WATERPUMP",
                        "DRIVESTRT","AC","STRNGWHL","DOOR","GEARSHIFT","SOUND",
                        "BREAKS","GRIND"};

    string clvarlt[776];
    string varble;
    string broke, issue, problem, carstart, battery, alternator, ip, ep, otheri,
           crissue, interiori, uh, oi, startm, ignition, distcap, gas, filter,
            baissue, engissue, pump, running, oheat, hc, sbelt, waterp,
          issueo, drivest, ac, swheal, door, gear, sound, brakew, brakeg;


    int instlt[32],
        statsk[32],
        clausk[32];

   int sn, f, i, j, s, k;
   int sp = 32;



    for (i=1; i<32; i++) {

       instlt[i]=0;
       statsk[i]=0;
       clausk[i]=0;
    }

   for (i=1; i<776; i++)  {
        clvarlt[i] = "";
   }

        clvarlt[1] = "CARISSUE";
        clvarlt[26] = "CARISSUE";
        clvarlt[51] = "BROKE";
        clvarlt[52] = "CARSTART";
        clvarlt[76]= "BROKE";
        clvarlt[77]= "CARSTART";
        clvarlt[101]= "EXT";
        clvarlt[102]= "BATTERY";
        clvarlt[103]= "ALT";
        clvarlt[126]= "EXT";
        clvarlt[127]= "BATTERY";
        clvarlt[128]= "ALT";
        clvarlt[151]= "EXT";
        clvarlt[152]= "BATTERY";
        clvarlt[153]= "STARTMTR";
        clvarlt[176]= "EXT";
        clvarlt[177]= "BATTERY";
        clvarlt[178]= "STARTMTR";
        clvarlt[179]= "IGNCOIL";
        clvarlt[201]=  "EXT";
        clvarlt[202]= "BATTERY";
        clvarlt[203]= "STARTMTR";
        clvarlt[204]= "IGNCOIL";
        clvarlt[205]= "DISTCAP";
        clvarlt[226]= "EXT";
        clvarlt[227]= "BATTERY";
        clvarlt[228]= "STARTMTR";
        clvarlt[229]= "IGNCOIL";
        clvarlt[230]= "DISTCAP";
        clvarlt[231]= "GASTANK";
        clvarlt[251]= "EXT";
        clvarlt[252]= "BATTERY";
        clvarlt[253]= "STARTMTR";
        clvarlt[254]= "IGNCOIL";
        clvarlt[255]= "DISTCAP";
        clvarlt[256]= "GASTANK";
        clvarlt[257]= "FUELFILTER";
        clvarlt[276] = "EXT";
        clvarlt[277]= "BATTERY";
        clvarlt[278]= "STARTMTR";
        clvarlt[279]= "IGNCOIL";
        clvarlt[280]= "DISTCAP";
        clvarlt[281]= "GASTANK";
        clvarlt[282]= "FUELFILT";
        clvarlt[283]= "FUELPUMP";
        clvarlt[301]= "EXT";
        clvarlt[302]= "BATTERY";
        clvarlt[303]= "STARTMTR";
        clvarlt[304]= "IGNCOIL";
        clvarlt[305]= "DISTCAP";
        clvarlt[306]= "GASTANK";
        clvarlt[307]= "FUELFILT";
        clvarlt[308]= "FUELPUMP";
        clvarlt[326]= "INT";
        clvarlt[327]= "STAYRUN";
        clvarlt[351]= "INT";
        clvarlt[352]= "STAYRUN";
        clvarlt[376]= "INTERIOR";
        clvarlt[377]= "OVERHEAT";
        clvarlt[378]= "COOLENT";
        clvarlt[379]= "SERPBELT";
        clvarlt[401]= "INTERIOR";
        clvarlt[402]= "OVERHEAT";
        clvarlt[403]= "COOLENT";
        clvarlt[404]= "SERPBELT";
        clvarlt[426]= "INTERIOR";
        clvarlt[427]= "OVERHEAT";
        clvarlt[428]= "COOLENT";
        clvarlt[429]= "WATERPUMP";
        clvarlt[451]= "INTERIOR";
        clvarlt[452]= "OVERHEAT";
        clvarlt[453]= "COOLENT";
        clvarlt[454]= "WATERPUMP";
        clvarlt[476]= "UNDRHOOD";
        clvarlt[477]= "GASTANK";
        clvarlt[501]= "UNDRHOOD";
        clvarlt[502]= "GASTANK";
        clvarlt[503]= "FUELFILT";
        clvarlt[526]= "UNDRHOOD";
        clvarlt[527]= "GASTANK";
        clvarlt[528]= "FUELFILT";
        clvarlt[529]= "FUELPUMP";
        clvarlt[551]= "UNDRHOOD";
        clvarlt[552]= "GASTANK";
        clvarlt[553]= "FUELFILT";
        clvarlt[554]= "FUELPUMP";
        clvarlt[576]= "INTERIOR";
        clvarlt[577]= "OVERHEAT";
        clvarlt[578]= "DRIVESTRT";
        clvarlt[601]= "INTERIOR";
        clvarlt[602]= "OVERHEAT";
        clvarlt[603]= "DRIVESTRT";
        clvarlt[604]= "AC";
        clvarlt[626]= "INTERIOR";
        clvarlt[627]= "OVERHEAT";
        clvarlt[628]= "DRIVESTRT";
        clvarlt[629]= "AC";
        clvarlt[630]= "STRNGWHL";
        clvarlt[651]= "INTERIOR";
        clvarlt[652]= "OVERHEAT";
        clvarlt[653]= "DRIVESTRT";
        clvarlt[654]= "AC";
        clvarlt[655]= "STRNGWHL";
        clvarlt[656]= "DOOR";
        clvarlt[676]= "INTERIOR";
        clvarlt[677]= "OVERHEAT";
        clvarlt[678]= "DRIVESTRT";
        clvarlt[679]= "AC";
        clvarlt[680]= "STRNGWHL";
        clvarlt[681]= "DOOR";
        clvarlt[682]= "GEARSHIFT";
        clvarlt[701]= "INTERIOR";
        clvarlt[702]= "OVERHEAT";
        clvarlt[703]= "DRIVESTRT";
        clvarlt[704]= "AC";
        clvarlt[705]= "STRNGWHL";
        clvarlt[706]= "DOOR";
        clvarlt[707]= "GEARSHIFT";
        clvarlt[708]= "SOUND";
        clvarlt[726]= "INTERIOR";
        clvarlt[727]= "OVERHEAT";
        clvarlt[728]= "DRIVESTRT";
        clvarlt[729]= "AC";
        clvarlt[730]= "STRNGWHL";
        clvarlt[731]= "DOOR";
        clvarlt[732]= "GEARSHIFT";
        clvarlt[733]= "SOUND";
        clvarlt[734]= "BREAKS";
        clvarlt[735]= "GRIND";

        clvarlt[751]= "INTERIOR";
        clvarlt[752]= "OVERHEAT";
        clvarlt[753]= "DRIVESTRT";
        clvarlt[754]= "AC";
        clvarlt[755]= "STRNGWHL";
        clvarlt[756]= "DOOR";
        clvarlt[757]= "GEARSHIFT";
        clvarlt[758]= "SOUND";
        clvarlt[759]= "BREAKS";
        clvarlt[760]= "GRIND";

        cout << "PLEASE TOUN ON CAPS LOCK TO RUN THIS PROGRAM\n";
        cout << "ENTER WHAT PROBLEM OF THE CAR YOU ARE TRYING TO FIND \n" ;
        cout << "BATTERY/ALTERNATOR-ISSUE \n" ;
        cout << "ENGINE-ISSUE \n";
        cout << "OTHER-ISSUE \n";
        cout << "CARRUN-ISSUE \n";
        cout << "INTERIOR-ISSUE \n";
        cin >> varble;

b520:   f= 1;
        determine_member_concl_list(sn, i, f,varble, conclt);
        if (sn != 0){
        do

        {
            push_on_stack(sp, statsk, sn, clausk);
            do

            {

b545:
               i = (statsk[sp] -1) *25 + clausk[sp];
               varble = clvarlt[i];


           if (varble != "") {
                 f = 1;

                  determine_member_concl_list(sn, i, f, varble, conclt);
                  if(sn != 0)

                          goto b520;

            instantiate(varble, varlt,  i, instlt,  issue,  carstart,
                  battery,  alternator,  startm,  ignition,  distcap,
                  gas, filter, pump, running,  oheat, hc, sbelt, waterp,
                  drivest,ac, swheal,  door, gear, sound, brakew, brakeg);

                  clausk[sp] = clausk[sp] + 1;


          }

              }
               while (varble != "");
                    sn = statsk[sp];
                    s = 0;


                switch (sn) {

                case 1: if(issue == "NO")
                        s = 1;
                        break;

                case 2: if(issue == "YES")
                        s = 1;
                        break;

                case 3: if(broke == "YES" && carstart == "YES")
                        s =1;
                        break;

                case 4: if(broke == "YES"  && carstart == "NO")
                        s =1;
                        break;

                case 5: if(ep == "YES" && battery == "NO" && alternator == "NO")
                        s =1;
                        break;

                case 6: if(ep == "YES" && battery == "NO" &&
                           alternator == "YES")
                        s = 1;
                        break;

                case 7: if((ep == "YES") && (battery == "YES") &&
                        (startm == "NO"))
                        s = 1;
                        break;

                case 8:  if((ep == "YES" )&& (battery == "YES" )&&
                            (startm == "YES") &&
                           (ignition == "NO"))  s = 1;
                            break;

                case 9: if(ep == "YES" && battery == "YES" && startm == "YES" &&
                        ignition == "YES" && distcap == "NO" )
                        s = 1;
                      break;

                case 10: if(ep == "YES" && battery == "YES" &&
                            startm == "YES" && ignition == "YES" &&
                            distcap == "YES" && gas == "YES") s = 1;
                            break;

                case 11: if(ep == "YES" &&
                            battery== "YES" &&
                            startm== "YES" &&
                            ignition== "YES" &&
                            distcap== "YES"&&
                            gas== "NO" &&
                            filter== "NO")
                            s = 1;
                            break;

                case 12: if(ep== "YES" &&
                            battery== "YES" &&
                            startm== "YES" &&
                            ignition== "YES" &&
                            distcap== "YES" &&
                            gas== "NO" &&
                            filter== "YES" &&
                            pump== "NO") s = 1;
                            break;

                case  13 : if(ep== "YES" &&
                                battery== "YES" &&
                                startm== "YES" &&
                                ignition== "YES" &&
                                distcap== "YES" &&
                                gas== "NO" &&
                                filter== "YES" &&
                                pump== "YES" ) s = 1;
                                break;


                case 14: if(ip== "YES" && running== "YES")
                           s= 1;
                           break;

                case 15: if(ip== "YES" && running== "NO" )
                          s= 1;
                         break;



                 case 16: if(oi== "YES" &&
                            oheat== "YES" &&
                            hc== "YES" &&
                            sbelt== "NO" ) s = 1;
                            break;

                case 17:  if(oi== "YES" &&
                            oheat== "YES" &&
                            hc== "YES" &&
                            sbelt== "YES" ) s = 1;
                            break;


                case 18: if(oi== "YES" &&
                            oheat== "YES" &&
                            hc== "NO"&&
                            waterp== "NO" )s = 1;
                            break;

                case 19: if(oi== "YES" &&
                            oheat== "YES" &&
                            hc== "NO"&&
                            waterp== "YES")s = 1;
                            break;

                case  20 : if(uh== "YES" &&
                              gas== "YES") s = 1;
                              break;

                case 21: if(uh== "YES" &&
                            gas== "NO" &&
                            filter== "NO") s = 1;
                            break;

                case 22: if(uh== "YES" &&
                            gas== "NO" &&
                            filter== "YES" &&
                            pump== "NO") s = 1;
                            break;

                case 23: if(uh== "YES" &&
                            gas== "NO" &&
                            filter== "YES" &&
                            pump== "YES") s = 1;
                            break;


                case 24: if(oi== "YES" &&
                            oheat== "NO" &&
                            drivest== "NO") s = 1;
                            break;


                case 25: if(oi== "YES" &&
                            oheat== "NO" &&
                            drivest== "YES" &&
                             ac== "NO") s = 1;
                              break;

                case 26: if(oi== "YES" &&
                            oheat== "NO" &&
                            drivest== "YES" &&
                             ac== "YES" &&
                             swheal== "NO") s = 1;
                              break;

                case 27: if(oi== "YES" &&
                            oheat== "NO" &&
                            drivest== "YES" &&
                             ac== "YES" &&
                             swheal== "YES" &&
                             door== "NO") s = 1;
                              break;


                case 28: if(oi== "YES" &&
                            oheat== "NO" &&
                            drivest== "YES" &&
                             ac== "YES" &&
                             swheal== "YES" &&
                             door== "YES" &&
                             gear== "NO" ) s = 1;
                              break;


                case 29: if(oi== "YES" &&
                            oheat== "NO" &&
                            drivest== "YES" &&
                             ac== "YES" &&
                             swheal== "YES" &&
                             door== "YES" &&
                             gear== "YES" &&
                             sound== "NO" ) s = 1;
                              break;

                case 30: if(oi== "YES" &&
                            oheat== "NO" &&
                            drivest== "YES" &&
                             ac== "YES" &&
                             swheal== "YES" &&
                             door== "YES" &&
                             gear== "YES" &&
                             sound== "YES" &&
                              brakew== "NO" &&
                              brakeg== "NO" ) s = 1;
                               break;

                case 31: if(oi== "YES" &&
                            oheat== "NO" &&
                            drivest== "YES" &&
                             ac== "YES" &&
                             swheal== "YES" &&
                             door== "YES" &&
                             gear== "YES" &&
                             sound== "YES" &&
                              brakew== "NO" &&
                              brakeg== "YES" ) s = 1;
                               break;


                }

    if( s != 1) {

        i = statsk[sp];
        varble = conclt[i];
        f = statsk[sp] + 1;
        determine_member_concl_list(sn, i, f,varble,conclt);
        sp = sp+1;

    }

    } while((s != 1) && (sn !=0));
      if(sn != 0){

      switch (sn) {

                          case 1: (problem= "NO");
                                  cout <<"THERE IS NO CAR PROBLEM\n";
                                  break;


                          case 2: (broke= "YES");
                                  cout <<"YOUR CAR HAS A PROBLEM\n";
                                  break;

                          case 3: (ip= "YES");
                                  cout <<"YOU HAVE AN INTERIOR PROBLEM\n";
                                  break;

                          case 4: (ep= "YES");
                                  cout <<"YOU HAVE AN UNDER THE HOOD PROBLEM\n";
                                  break;


                          case 5: (baissue= "YES");
                                  cout <<"YOUR ALTERNATOR IS THE ISSUE REPAIR #1\n";
                                 
                                  break;

                          case 6: (baissue= "YES");
                                  cout <<"YOUR BATTEY IS THE ISSUE REPAIR #2\n";
                               
                                  break;


                        case 7:  (engissue= "YES");
                                  cout <<"YOUR START MOTOR IS THE ISSUE REPAIR #3\n";
                                 
                                  break;

                          case 8: (engissue= "YES");
                                  cout <<"YOUR IGNITION COIL IS THE ISSUE REPAIR #4\n";
                                
                                  break;

                        case 9:(engissue= "YES");
                                  cout <<"YOUR DIST CAP IS THE ISSUE REPAIR #5\n";
                                
                                  break;

                        case 10: (engissue= "YES");
                                  cout <<"AN EMPTY GAS TANK IS YOUR ISSUE REPAIR #6\n";
                                 
                                  break;

                        case 11: (engissue= "YES");
                                  cout <<" THE FUEL FILTER IS THE ISSUE REPAIR #7\n";
                                    
                                  break;

                        case 12: (engissue= "YES");
                                cout <<"THE FUEL PUMP IS THE ISSUEREPAIR #8\n";
                              
                                break;

                        case 13: (engissue= "YES");
                                cout <<"THE FUEL INJECTOR IS THE ISSUE REPAIR #9\n";
                                 
                                break;

                         case 14: (oi= "YES");
                                cout <<"THE ISSUE IS NOT UNDER THE HOOD\n";
                                break;

                            case 15: (uh= "YES");
                                cout <<"THE ISSUE IS UNDER THE HOOD \n";
                                break;


                     case 16: (otheri= "YES");
                                cout <<"SERPENTIN BELT IS THE ISSUE REPAIR #10\n";
                                 
                                break;

                    case 17: (otheri= "YES");
                                cout <<"THE SENSOR IS BROKE REPAIR #11\n";
                              
                                break;

                          case 18: (issueo= "YES");
                                cout <<"THE WATER PUMP IS THE ISSUE REPAIR #12\n";
                                 
                                break;

                         case 19: (issueo= "YES");
                                cout <<"THE SENSOR IS BROKE REPAIR #11\n";
                                 
                                break;

                     case 20: (crissue= "YES");
                                cout <<"THE GAS TANK IS EMPTY REPAIR #6\n";
                                 
                                 
                                break;

                    case 21: (crissue= "YES");
                                cout <<"THE FUEL FILTER IS THE ISSUE REPAIR #7\n";
                              
                                 
                                break;

                    case 22: (crissue= "YES");
                                cout <<"THE FUEL PUMP IS THE ISSUE REPAIR #8\n";
                                 
                                 
                                break;

                    case 23: (crissue= "YES");
                                cout <<"THE FUEL INJECTOR IS THE ISSUE REPAIR #9\n";
                                 
                                 
                                break;

                    case 24: (interiori = "YES");
                            cout <<"THE ALLIGHNMENT OF THE CAR IS THE ISSUE REPAIR #14\n";
                           
                           
                            break;
                      case 25: (interiori = "YES");
                                cout <<"THE AC IS THE ISSUE REPAIR #15\n";
                              
                                 
                                break;

                      case 26: (interiori = "YES");
                                cout <<"THE STEERING WHEEL IS THE ISSUE REPAIR #16\n";
                                 
                                 
                                break;

                      case 27: (interiori = "YES");
                                cout <<"THE DOOR IS THE ISSUE REPAIR #17\n";
                                 
                               
                                break;

                      case 28: (interiori = "YES");
                                cout <<"THE GEAR SHIFT IS THE ISSUE REPAIR #18\n";
                                
                                 
                                break;

                      case 29: (interiori = "YES");
                                cout <<"THE SPEAKERS ARE THE ISSUE REPAIR #19\n";
                                 
                                 
                                break;

                      case 30: (interiori = "YES");
                                cout <<"THE PEDAL IS THE ISSUE REPAIR # 13\n";
                                 
                              
                                break;

                     case 31: (interiori = "YES");
                                cout <<"THE BRAKE IS THE ISSUE REPAIR # 20\n";
                              
                                 
                                break;


            }

                          sp=sp+1;
                          if(sp >= 32)

                                  cout << "*** SUCCESS\n";
                          else {

                                  clausk[sp] = clausk[sp]+1;
                                  goto b545;
                          }
                  }
        }
/* <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><> */
   
   cout << "\n\nFOR REPAIRS ENTER THE REPAIR #\n";
   cout << "OR ENTER 0 TO QUIT. : ";
   cin >> repairCode;
   
   switch(repairCode){
      case 1:conditionVariable = "alternatorIssue";break;
      case 2:conditionVariable = "batteryIssue";break;
      case 3:conditionVariable = "starterMotorIssue";break;
      case 4:conditionVariable = "ignCoIssue";break;
      case 5:conditionVariable = "distCapIssue";break;
      case 6:conditionVariable = "gasTankEmIssue";break;
      case 7:conditionVariable = "fuleFtrIssue";break;
      case 8:conditionVariable = "fulePumpIssue";break;
      case 9:conditionVariable = "fuleInjIssue";break;
      case 10:conditionVariable = "serpBltIssue";break;
      case 11:conditionVariable = "sensorIssue";break;
      case 12:conditionVariable = "waterPumpIssue";break;
      case 13:conditionVariable = "pedalIssue";break;
      case 14:conditionVariable = "alignmentIssue";break;
      case 15:conditionVariable = "airConIssue";break;
      case 16:conditionVariable = "strWhIssue";break;
      case 17:conditionVariable = "doorIssue";break;
      case 18:conditionVariable = "gearIssue";break;
      case 19:conditionVariable = "speakerIssue";break;
      case 20:conditionVariable = "brkIssue";break;
      default: break;
   }
   
   conclutionQueue[backPtr] = conditionVariable;
   backPtr++;
   statmentNum = 1;
   clauseNum = 1;
   firstStm = 1;
   
   bool flag = false;
   /* These nested loops should take care of the goto stmt.*/
   while (!flag){                      /*  <------- loop 3 */
      while(!flag){                    /*  <------- loop 2 */
         while(!flag){                 /*  <------- loop 1 */
            flag = true;
            search(clauseVariableLst,conclutionQueue,clauseNum,statmentNum,frontPtr,firstStm);
            clauseNum = 1;
            if(statmentNum != 0){
               k2 = 4 * (statmentNum - 1) + clauseNum;
               variable = clauseVariableLst[k2];
               while(variable != ""){
                  check_instantiation(variable,variableLst,instlt2,batteryIssue,
                                      alternatorIssue,starterMotorIssue,pedalIssue,
                                      speakerIssue,doorIssue,strWhIssue,fuleInjIssue,
                                      fulePumpIssue,fuleFtrIssue,gasTankEmIssue,
                                      sensorIssue,waterPumpIssue,serpBltIssue,
                                      ignCoIssue,distCapIssue,alignmentIssue,airConIssue,
                                      gearIssue,brkIssue);
                  clauseNum++;
                  k2 = 4 * (statmentNum - 1) + clauseNum;
                  variable = clauseVariableLst[k2];
               }
               setVal = 0;
      /* This switch() is for the IF parts */
               switch(statmentNum){
                 
                  case 1: if(battery2 == "NO") {setVal = 1;} break;
                  case 2: if(battery2 == "YES") {setVal = 1;} break;
                  case 3: if(batteryIssue == "YES") {setVal = 1;} break;
                  case 4: if(batteryIssue == "NO"){setVal = 1;} break;
                     
                  case 5: if(alternator2 == "NO") {setVal = 1;} break;
                  case 6: if(alternator2 == "YES") {setVal = 1;} break;
                  case 7: if(alternatorIssue == "YES") {setVal = 1;} break;
                  case 8: if(alternatorIssue == "NO"){setVal = 1;} break;
                     
                  case 9: if(starterMotor2 == "NO") {setVal = 1;} break;
                  case 10: if(starterMotor2 == "YES") {setVal = 1;} break;
                  case 11: if(starterMotorIssue == "YES") {setVal = 1;} break;
                  case 12: if(starterMotorIssue == "NO"){setVal = 1;} break;
                     
                  case 13: if(pedal2 == "NO") {setVal = 1;} break;
                  case 14: if(pedal2 == "YES") {setVal = 1;} break;
                  case 15: if(pedalIssue == "YES") {setVal = 1;} break;
                  case 16: if(pedalIssue == "NO"){setVal = 1;} break;
                     
                  case 17: if(speaker2 == "NO") {setVal = 1;} break;
                  case 18: if(speaker2 == "YES") {setVal = 1;} break;
                  case 19: if(speakerIssue == "YES") {setVal = 1;} break;
                  case 20: if(speakerIssue == "NO"){setVal = 1;} break;
                     
                  case 21: if(door2 == "NO") {setVal = 1;} break;
                  case 22: if(door2 == "YES") {setVal = 1;} break;
                  case 23: if(doorIssue == "YES") {setVal = 1;} break;
                  case 24: if(doorIssue == "NO"){setVal = 1;} break;
                     
                  case 25:if(strWh2 == "NO") {setVal = 1;} break;
                  case 26:if(strWh2 == "YES") {setVal = 1;} break;
                  case 27:if(strWhIssue == "YES") {setVal = 1;} break;
                  case 28:if(strWhIssue == "NO") {setVal = 1;} break;
                    
                  case 29:if(fuleInj2 == "NO") {setVal = 1;} break;
                  case 30:if(fuleInj2 == "YES") {setVal = 1;} break;
                  case 31:if(fuleInjIssue == "YES") {setVal = 1;} break;
                  case 32:if(fuleInjIssue == "NO") {setVal = 1;} break;
                     
                  case 33:if(fulePump2 == "NO") {setVal = 1;} break;
                  case 34:if(fulePump2 == "YES") {setVal = 1;} break;
                  case 35:if(fulePumpIssue == "YES") {setVal = 1;} break;
                  case 36:if(fulePumpIssue == "NO") {setVal = 1;} break;
                    
                  case 37:if(fuleFtr2 == "NO") {setVal = 1;} break;
                  case 38:if(fuleFtr2 == "YES") {setVal = 1;} break;
                  case 39:if(fuleFtrIssue == "YES") {setVal = 1;} break;
                  case 40:if(fuleFtrIssue == "NO") {setVal = 1;} break;
                     
                  case 41:if(gasTankEm2 == "NO") {setVal = 1;} break;
                  case 42:if(gasTankEm2 == "YES") {setVal = 1;} break;
                  case 43:if(gasTankEmIssue == "YES") {setVal = 1;} break;
                  case 44:if(gasTankEmIssue == "NO") {setVal = 1;} break;

                  case 45:if(sensor2 == "NO") {setVal = 1;} break;
                  case 46:if(sensor2 == "YES") {setVal = 1;} break;
                  case 47:if(sensorIssue == "YES") {setVal = 1;} break;
                  case 48:if(sensorIssue == "NO") {setVal = 1;} break;
                    
                  case 49:if(waterPump2 == "NO") {setVal = 1;} break;
                  case 50:if(waterPump2 == "YES") {setVal = 1;} break;
                  case 51:if(waterPumpIssue == "YES") {setVal = 1;} break;
                  case 52:if(waterPumpIssue == "NO") {setVal = 1;} break;
                     
                  case 53:if(serpBlt2 == "NO") {setVal = 1;} break;
                  case 54:if(serpBlt2 == "YES") {setVal = 1;} break;
                  case 55:if(serpBltIssue == "YES") {setVal = 1;} break;
                  case 56:if(serpBltIssue == "NO") {setVal = 1;} break;
                    
                  case 57:if(ignCo2 == "NO") {setVal = 1;} break;
                  case 58:if(ignCo2 == "YES") {setVal = 1;} break;
                  case 59:if(ignCoIssue == "YES") {setVal = 1;} break;
                  case 60:if(ignCoIssue == "NO") {setVal = 1;} break;
                     
                  case 61:if(distCap2 == "NO") {setVal = 1;} break;
                  case 62:if(distCap2 == "YES") {setVal = 1;} break;
                  case 63:if(distCapIssue == "YES") {setVal = 1;} break;
                  case 64:if(distCapIssue == "NO") {setVal = 1;} break;
                     
                  case 65:if(alignment2 == "NO") {setVal = 1;} break;
                  case 66:if(alignment2 == "YES") {setVal = 1;} break;
                  case 67:if(alignmentIssue == "YES") {setVal = 1;} break;
                  case 68:if(alignmentIssue == "NO") {setVal = 1;} break;
                     
                  case 69:if(airCon2 == "NO") {setVal = 1;} break;
                  case 70:if(airCon2 == "YES") {setVal = 1;} break;
                  case 71:if(airConIssue == "YES") {setVal = 1;} break;
                  case 72:if(airConIssue == "NO") {setVal = 1;} break;
                     
                  case 73:if(gear2 == "NO") {setVal = 1;} break;
                  case 74:if(gear2 == "YES") {setVal = 1;} break;
                  case 75:if(gearIssue == "YES") {setVal = 1;} break;
                  case 76:if(gearIssue == "NO") {setVal = 1;} break;
                     
                  case 77:if(brk2 == "NO") {setVal = 1;} break;
                  case 78:if(brk2 == "YES") {setVal = 1;} break;
                  case 79:if(brkIssue == "YES") {setVal = 1;} break;
                  case 80:if(brkIssue == "NO") {setVal = 1;} break;

                  default:break;
               }
               if(setVal != 1){
                  firstStm = statmentNum + 1;
                  flag = false;
               }
            }
         }          /*  <-------------------------------------- End of loop 1 */
         if(statmentNum != 0){
      /* This switch() is for THEN */
            switch(statmentNum){
               case 1:
                  battRepair = "NO";
                  std::cout <<  "REPAIR: THE BATTERY WILL HAVE TO BE REPLACED\n";
                  variable = "battRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 2:
                  battRepair = "YES";
                  std::cout <<  "REPAIR: ADD WATER TO BATTERY\n";
                  variable = "battRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 3:
                  battery2 = "NO";
                  std::cout <<"The battery canNOt be repaired\n";
                  variable = "battery";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 4:
                  battery2 = "YES";
                  std::cout << "The battery can be repaired\n";
                  variable = "battery";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 5:
                  altRepair = "NO";
                  std::cout <<  "REPAIR: THE ALTERNATOR WILL HAVE TO BE REPLACED\n";
                  variable = "altRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 6:
                  altRepair = "YES";
                  std::cout <<  "REPAIR: FIX ALTERNATOR\n";
                  variable = "altRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 7:
                  alternator2 = "NO";
                  std::cout <<"The alternator canNOt be repaired\n";
                  variable = "alternator";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 8:
                  alternator2 = "YES";
                  std::cout << "The alternator can be repaired\n";
                  variable = "alternator";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 9:
                  stMoRepair = "NO";
                  std::cout <<  "REPAIR: THE STMO WILL HAVE TO BE REPLACED\n";
                  variable = "stMoRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 10:
                  stMoRepair = "YES";
                  std::cout <<  "REPAIR: FIX STMO\n";
                  variable = "stMoRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 11:
                  starterMotor2 = "NO";
                  std::cout <<"The stmo canNOt be repaired\n";
                  variable = "starterMotor";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 12:
                  starterMotor2 = "YES";
                  std::cout << "The stmo can be repaired\n";
                  variable = "starterMotor";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 13:
                  pedalRepair = "NO";
                  std::cout <<  "REPAIR: THE pedal WILL HAVE TO BE REPLACED\n";
                  variable = "pedalRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 14:
                  pedalRepair = "YES";
                  std::cout <<  "REPAIR: pedal\n";
                  variable = "pedalRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 15:
                  pedal2 = "NO";
                  std::cout <<"The pedal canNOt be repaired\n";
                  variable = "pedal";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 16:
                  pedal2 = "YES";
                  std::cout << "The pedal can be repaired\n";
                  variable = "pedal";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 17:
                  speakerRepair = "NO";
                  std::cout <<  "REPAIR: THE speaker WILL HAVE TO BE REPLACED\n";
                  variable = "speakerRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 18:
                  speakerRepair = "YES";
                  std::cout <<  "REPAIR: FIX speaker\n";
                  variable = "speakerRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 19:
                  speaker2 = "NO";
                  std::cout <<"The speaker canNOt be repaired\n";
                  variable = "speaker";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 20:
                  speaker2 = "YES";
                  std::cout << "The speaker can be repaired\n";
                  variable = "speaker";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 21:
                  doorRepair = "NO";
                  std::cout <<  "REPAIR: THE door WILL HAVE TO BE REPLACED\n";
                  variable = "doorRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 22:
                  doorRepair = "YES";
                  std::cout <<  "REPAIR: FIX door\n";
                  variable = "doorRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 23:
                  door2 = "NO";
                  std::cout <<  "REPAIR: THE door WILL HAVE TO BE REPLACED\n";
                  variable = "door";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 24:
                  door2 = "YES";
                  std::cout <<  "REPAIR: FIX door\n";
                  variable = "door";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 25:
                  strWhRepair = "NO";
                  std::cout <<  "REPAIR: THE strWh WILL HAVE TO BE REPLACED\n";
                  variable = "strWhRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 26:
                  strWhRepair = "YES";
                  std::cout <<  "REPAIR: FIX strWh\n";
                  variable = "strWhRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 27:
                  strWh2 = "NO";
                  std::cout <<"The strWh canNOt be repaired\n";
                  variable = "strWh";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 28:
                  strWh2 = "YES";
                  std::cout << "The strWh can be repaired\n";
                  variable = "strWh";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 29:
                  fuleInjRepair = "NO";
                  std::cout <<  "REPAIR: THE  FULE INJECTOR WILL HAVE TO BE REPLACED\n";
                  variable = "fuleInjRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 30:
                  fuleInjRepair = "YES";
                  std::cout <<  "REPAIR: CLEAN FULE INJECTOR\n";
                  variable = "fuleInjRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 31:
                  fuleInj2 = "NO";
                  std::cout <<"The fuleInjector cannot be repaired\n";
                  variable = "fuleInj";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 32:
                  fuleInj2 = "YES";
                  std::cout << "The n fuleinjector can be repaired\n";
                  variable = "fuleInj";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 33:
                  fulePumpRepair = "NO";
                  std::cout <<  "REPAIR: THE FULEPUMP WILL HAVE TO BE REPLACED\n";
                  variable = "fulePumpRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 34:
                  fulePumpRepair = "YES";
                  std::cout <<  "REPAIR: CONNECT fulePump\n";
                  variable = "fulePumpRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 35:
                  fulePump2 = "NO";
                  std::cout <<"The fulePump cannot be repaired\n";
                  variable = "fulePump";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 36:
                  fulePump2 = "YES";
                  std::cout << "The fulePump can be repaired\n";
                  variable = "fulePump";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 37:
                  fuleFtrRepair = "NO";
                  std::cout <<  "REPAIR: THE FULER FILTER WILL HAVE TO BE REPLACED\n";
                  variable = "fuleFtrRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 38:
                  fuleFtrRepair = "YES";
                  std::cout <<  "REPAIR: CONNECT FULER FILTER\n";
                  variable = "fuleFtrRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 39:
                  fuleFtr2 = "NO";
                  std::cout <<"The fuleFtr cannot be repaired\n";
                  variable = "fuleFtr";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 40:
                  fuleFtr2 = "YES";
                  std::cout << "The fuleFtr can be repaired\n";
                  variable = "fuleFtr";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 41:
                  gasTankEmRepair = "NO";
                  std::cout <<  "REPAIR: THE GAS TANK WILL HAVE TO BE REPLACED\n";
                  variable = "gasTankEmRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 42:
                  gasTankEmRepair = "YES";
                  std::cout <<  "REPAIR: FILL GAS TANK\n";
                  variable = "gasTankEmRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 43:
                  gasTankEm2 = "NO";
                  std::cout <<"The gas tank cannot be repaired\n";
                  variable = "gasTankEm";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 44:
                  gasTankEm2 = "YES";
                  std::cout << "The gas tank can be repaired\n";
                  variable = "gasTankEm";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 45:
                  sensorRepair = "NO";
                  std::cout <<  "REPAIR: THE sensor WILL HAVE TO BE REPLACED\n";
                  variable = "sensorRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 46:
                  sensorRepair = "YES";
                  std::cout <<  "REPAIR: Clean SENSOR\n";
                  variable = "sensorRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 47:
                  sensor2 = "NO";
                  std::cout <<  "sensor cannot be repaird\n";
                  variable = "sensor";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 48:
                  sensor2 = "YES";
                  std::cout <<  "sensor can be repaird\n";
                  variable = "sensor";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 49:
                  waterPumpRepair = "NO";
                  std::cout <<  "REPAIR: THE WATERPUMP WILL HAVE TO BE REPLACED\n";
                  variable = "waterPumpRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 50:
                  waterPumpRepair = "YES";
                  std::cout <<  "REPAIR: CONNECT WATERPUMP\n";
                  variable = "waterPumpRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 51:
                  waterPump2 = "NO";
                  std::cout <<"The waterPump cannot be repaired\n";
                  variable = "waterPump";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 52:
                  waterPump2 = "YES";
                  std::cout << "The waterPump can be repaired\n";
                  variable = "waterPump";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 53:
                  serpBltRepair = "NO";
                  std::cout <<  "REPAIR: REPLACE BELT\n";
                  variable = "serpBltRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 54:
                  serpBltRepair = "YES";
                  std::cout <<  "REPAIR: STILL REPLACE BELT\n";
                  variable = "serpBltRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 55:
                  serpBlt2 = "NO";
                  std::cout <<"The serpintinebelt cannot be repaired\n";
                  variable = "serpBlt";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 56:
                  serpBlt2 = "YES";
                  std::cout << "The serpintinebelt can be repaired\n";
                  variable = "serpBlt";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 57:
                  ignCoRepair = "NO";
                  std::cout <<  "REPAIR: THE INGNITIONCOIL WILL HAVE TO BE REPLACED\n";
                  variable = "ignCoRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 58:
                  ignCoRepair = "YES";
                  std::cout <<  "REPAIR: CONNECT IGNITIONCOIL\n";
                  variable = "ignCoRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 59:
                  ignCo2 = "NO";
                  std::cout <<"The ignitioncoil cannot be repaired\n";
                  variable = "ignCo";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 60:
                  ignCo2 = "YES";
                  std::cout << "The ignitioncoil can be repaired\n";
                  variable = "ignCo";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 61:
                  distCapRepair = "NO";
                  std::cout <<  "REPAIR: THE DISTCAP WILL HAVE TO BE REPLACED\n";
                  variable = "distCapRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 62:
                  distCapRepair = "YES";
                  std::cout <<  "REPAIR: CONNECT THE DISTCAP\n";
                  variable = "distCapRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 63:
                  distCap2 = "NO";
                  std::cout <<"The distCap cannot be repaired\n";
                  variable = "distCap";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 64:
                  distCap2 = "YES";
                  std::cout << "The distributor cap can be repaired\n";
                  variable = "distCap";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 65:
                  alignmentRepair = "NO";
                  std::cout <<  "REPAIR: REBALENCE LEFT SIDE WHEELS\n";
                  variable = "alignmentRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 66:
                  alignmentRepair = "YES";
                  std::cout <<  "REPAIR: REBALENCE RIGHT SIDE WHEELS\n";
                  variable = "alignmentRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 67:
                  alignment2 = "NO";
                  std::cout <<"The aligmnt can be repaired\n";
                  variable = "alignment";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 68:
                  alignment2 = "YES";
                  std::cout << "The alignment can be repaired\n";
                  variable = "alignment";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 69:
                  airConRepair = "NO";
                  std::cout <<  "REPAIR: THE CONDENSOR WILL HAVE TO BE REPLACED\n";
                  variable = "airConRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 70:
                  airConRepair = "YES";
                  std::cout <<  "REPAIR: ADD FREON\n";
                  variable = "airConRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 71:
                  airCon2 = "NO";
                  std::cout <<"The A/C cannot be repaired\n";
                  variable = "airCon";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 72:
                  airCon2 = "YES";
                  std::cout << "The A/C can be repaired\n";
                  variable = "airCon";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 73:
                  gearRepair = "NO";
                  std::cout <<  "REPAIR: THE GEAR WILL HAVE TO BE REPLACED\n";
                  variable = "gearRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 74:
                  gearRepair = "YES";
                  std::cout <<  "REPAIR: ADD OIL TO GEARSHIFTER\n";
                  variable = "gearRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 75:
                  gear2 = "NO";
                  std::cout << "The GEAR cannot be repaired\n";
                  variable = "gear";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 76:
                  gear2 = "YES";
                  std::cout << "The gear shift can be repaired\n";
                  variable = "gear";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 77:
                  brkRepair = "NO";
                  std::cout <<  "REPAIR: THE BREAKS WILL HAVE TO BE REPLACED\n";
                  variable = "brkRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 78:
                  brkRepair = "YES";
                  std::cout <<  "REPAIR: FIX BREAKS\n";
                  variable = "brkRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 79:
                  brk2 = "NO";
                  std::cout <<  "The BREAKS canNOt be repaired\n";
                  variable = "brk";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 80:
                  brk2 = "YES";
                  std::cout <<  "The breaks can be repaired\n";
                  variable = "brk";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               default:
                  break;
            }
            firstStm = statmentNum + 1;
            flag = false;
         }
      }
      frontPtr++;
      if(frontPtr < backPtr){
         firstStm = 1;
         flag = false;
      }
      else
         flag = true;
   }
   return 0;

 }
/* <><><><><><><><><><><><><><> END OF MAIN <><><><><><><><><><><><><><><><> */
 





void determine_member_concl_list(int& sn,int& i, int& f,
                                  string& varble, string* conclt) {
        sn = 0;
        i = f;
        while(varble != conclt[i] && i<31)
              i=i+1;
        if (varble == conclt[i])
             sn = i;

}
void push_on_stack(int& sp, int* statsk, int& sn, int* clausk)
{
        sp=sp-1;
        statsk[sp] = sn;
        clausk[sp] = 1;
}
void instantiate(string& varble, string* varlt, int& i, int* instlt,
                 string& issue, string& carstart, string&  battery,
                 string& alternator, string& startm,string& ignition,
                  string& distcap, string& gas,  string& filter,
                  string& pump, string& running, string& oheat, string& hc,
                  string& sbelt, string& waterp, string& drivest, string& ac,
                  string& swheal, string& door, string& gear, string& sound,
                  string& brakew, string& brakeg )

{
        i=1;
        while(varble != varlt[i] && i < 24) i=i+1;
        if(varble == varlt[i] && instlt[i] != 1)
{

                instlt[i]=1;
                switch (i)
                {

        case 1: cout <<"INPUT YES OR NO IF YOU HAVE A CAR ISSUE-? ";
                        cin >>issue;
                        break;
        case 2: cout <<"INPUT YES OR NO IF CAR START-? ";
                        cin >>carstart;
                        break;
        case 3: cout <<"INPUT YES OR NO IF BATTERY IS OKAY? ";
                        cin >>battery;
                        break;
        case 4: cout <<"INPUT YES OR NO IF ALTERNATOR IS OKAY-? ";
                        cin >>alternator;
                        break;

        case 5: cout <<"INPUT YES OR NO IF STARTMOTOR IS OKAY-? ";
                       cin >>startm;
                        break;

        case 6: cout <<"INPUT YES OR NO IF IGNITION COIL IS OKAY-? ";
                       cin >>ignition;
                        break;

        case 7: cout <<"INPUT YES OR NO IF DISTRIBUTER CAP IS OKAY-? ";
                       cin >>distcap;
                        break;

        case 8: cout <<"INPUT YES OR NO IF GAS IS  EMPTY-? ";
                       cin >>gas;
                        break;

                 case 9: cout <<"INPUT YES OR NO IF FUEL FILTER IS OKAY-? ";
                       cin >>filter;
                        break;

                 case 10: cout <<"INPUT YES OR NO IF FUEL PUMP IS OKAY-? ";
                       cin >>pump;
                        break;

              case 11: cout <<"INPUT YES OR NO IF CAR STAY RUNNING-? ";
                       cin >>running;
                        break;

            case 12: cout <<"INPUT YES OR NO IF CAR OVER HEATS -? ";
                    cin >>oheat;
                    break;

            case 13: cout <<"INPUT YES OR NO IF CAR HAS COOLENT-? ";
                    cin >>hc;
                    break;

            case 14: cout <<"INPUT YES OR NO IF SERPENTIN BELT IS OKAY-? ";
                    cin >>sbelt;
                    break;

            case 15: cout <<"INPUT YES OR NO IF WATER PUMP IS OKAY-? ";
                    cin >>waterp;
                    break;


            case 16: cout <<"INPUT YES OR NO IF CAR DRIVE STRAIGHT -? ";
                    cin >>drivest;
                    break;

            case 17: cout <<"INPUT YES OR NO IF THE AC BLOWS COOL && HOT AIR? ";
                     cin >>ac;
                    break;

            case 18: cout <<"INPUT YES OR NO IF STEARING WHEAL TURNS  -? ";
                    cin >>swheal;
                    break;


            case 19: cout <<"INPUT YES OR NO IF DOOR WORKS PROBLEM  -? ";
                    cin >>door;
                    break;

            case 20: cout <<"INPUT YES OR NO IF GEAR SHIFT WORK  -? ";
                    cin >>gear;
                    break;

            case 21: cout <<"INPUT YES OR NO IF SOUND WORKS  -? ";
                    cin >>sound;
                    break;

            case 22: cout <<"MUST BE AN BRAKES ISSUE\n ";
                    brakew = "YES";
                    break;

            case 23: cout <<"INPUT YES OR NO IF BRAKES MAKE A GRINDING NOISE? ";
                    cin >>brakeg;
                    break;


                }

}
}

/* <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
<> void search()                                                             <>
<> search for value                 <>
<>on the clause list.                  <>
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><> */

void search(string* cVL, string* cQ, int& cn, int& sn, int& fp,int& fs){
   bool flag = true;
   int k;
   sn = fs;
   while(flag == true && sn < 81){
      cn = 1;
      k = 4 * (sn - 1) + cn;

      while(cVL[k] != cQ[fp] && cn < 4){
         cn++;
         k = 4 * (sn - 1) + cn;
      }
      if(cVL[k] == cQ[fp])
         flag = false;
      if(flag == true)
         sn++;
   }
   if(flag == true)
      sn = 0;
}

/* <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
<> void check_instantiation() <>
<>  checks to see if issue
<> is on Q.
<>                            <>
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><> */

void check_instantiation(string& var, string* varLs, int* inst,
                         string& batt, string& alt, string& stmo,
                         string& ped, string& spk, string& dr,
                         string& sw, string& fI, string& fP,
                         string& fF, string& gT, string& s,
                         string& wP,string& sB, string& iG,
                         string& dC,string& aM,string& aC,
                         string& g, string& bK){
   int i = 1;
   while(var != varLs[i] && i < 62)
      i++;
   if(inst[i] != 1){
      inst[i] = 1;
      switch(i){
         case 1:
            std::cout << "Is the battery maintenance free?(YES or NO):  ";
            std::cin>> batt;
            break;
         case 2:
            std::cout << "Is the alternator connected?(YES or NO): ";
            std::cin>> alt;
            break;
         case 3:
            std::cout << "Is the starter motor connected?(YES or NO): ";
            std::cin>> stmo;
            break;
         case 4:
            std::cout << "Is the pedal broken?(YES or NO): ";
            std::cin>> ped;
            break;
         case 5:
            std::cout << "Is the speaker blown? (YES or NO): ";
            std::cin>> spk;
            break;
         case 6:
            std::cout << "Is the door latch broken?(YES or NO):  ";
            std::cin>> dr;
            break;
         case 7:
            std::cout << "Does the steeringwheel shake?(YES or NO): ";
            std::cin>> sw;
            break;
         case 8:
            std::cout << "Is the fule injector clogged?(YES or NO): ";
            std::cin>> fI;
            break;
         case 9:
            std::cout << "Is the fule pump connected?(YES or NO): ";
            std::cin>> fP;
            break;
         case 10:
            std::cout << "Is the fule filter connected?(YES or NO): ";
            std::cin>> fF;
            break;
         case 11:
            std::cout << "Does the gastank have a hole in it?(YES or NO): ";
            std::cin>> gT;
            break;
         case 12:
            std::cout << "Is the sensor dirty?(YES or NO): ";
            std::cin>> s;
            break;
         case 13:
            std::cout << "Is the water pump connected?(YES or NO): ";
            std::cin>> wP;
            break;
         case 14:
            std::cout << "Is the serpentine belt present? (YES or NO): ";
            std::cin>> sB;
            break;
         case 15:
            std::cout << "Is the ingnitioncoil connected?(YES or NO): ";
            std::cin>> iG;
            break;
         case 16:
            std::cout << "Is the distributer cap broken?(YES or NO): ";
            std::cin>> dC;
            break;
         case 17:
            std::cout << "Does the car pull tho the left?(YES or NO): ";
            std::cin>> aM;
            break;
         case 18:
            std::cout << "Does the A/C system have freon?(YES or NO): ";
            std::cin>> aC;
            break;
         case 19:
            std::cout << "Does the gearshift make noise?(YES or NO): ";
            std::cin>> g;
            break;
         case 20:
            std::cout << "Do the breaks make noise?(YES or NO): ";
            std::cin>> bK;
            break;
         
      }
   }
}

/* <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
<> void instantiate()   <>
<>                      <>
<>                      <>
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><> */

void instantiate(string& var, string* varLs, string* cQ, int* inst, int& bp){
   int i = 1;
   while(var !=  varLs[i] && i < 62)
      i++;
   inst[i] = 1;
   i = 1;
   while(var != cQ[i] && i < 62)
      i++;
   if(var != cQ[i]){
      cQ[bp] = var;
      bp++;
   }
}
