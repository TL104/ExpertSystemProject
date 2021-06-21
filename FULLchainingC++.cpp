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
//                        56
               variableLst[] = {"","batteryIssue","alternatorIssue",
                                "starterMotorIssue","pedalIssue","speakerIssue",
                                "doorIssue","strWhIssue","fuleInjIssue",
                                "fulePumpIssue","fuleFtrIssue","gasTankEmIssue",
                                "sensorIssue","waterPumpIssue","serpBltIssue",
                                "ignCoIssue","distCapIssue","alignmentIssue",
                                
                                "airConIssue", "gearIssue","brkIssue",
                               
                                "battery","battRepair",
                                "alternator","altRepair",
                                "starterMotor","stMoRepair",
                                "pedal","pedalRepair",
                                "speaker","speakerRepair",
                                "door", "doorRepair",
                                "strWh", "strWhRepair",
                                "fuleInj", "fuleInjRepair",
                                "fulePump", "fulePumpRepair",
                                "fuleFtr", "fuleFtrRepair",
                                "gasTankEm", "gasTankEmRepair",
                                "sensor", "sensorRepair",
                                "waterPump", "waterPumpRepair",
                                "serpBlt", "serpBltRepair",
                                "ignCo", "ignCoRepair",
                                "distCap", "distCapRepair",
                                "alignment", "alignmentRepair",
                                "airCon", "airConRepair",
                                "gear", "gearRepair",
                                "brk", "brkRepair",
                                ""},
                              
               clauseVariableLst[321],
               conditionVariable,
               variable,
              
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
       setVal,                         //
       instlt2[62];
   
   for(int i = 0; i < 62; i++)
      instlt2[i] = 0;
   
   for(int i = 0; i < 321; i++)        // Fills clauseVariableLst[] elements with ""
      clauseVariableLst[i] = "";
  
   clauseVariableLst[1] = "battery";           // 1
   clauseVariableLst[5] = "battery";
   clauseVariableLst[9] = "batteryIssue";
   clauseVariableLst[13] = "batteryIssue";
   
   clauseVariableLst[17] = "alternator";           // 2
   clauseVariableLst[21] = "alternator";
   clauseVariableLst[25] = "alternatorIssue";
   clauseVariableLst[29] = "alternatorIssue";
   
   clauseVariableLst[33] = "starterMotor";           // 3
   clauseVariableLst[37] = "starterMotor";
   clauseVariableLst[41] = "starterMotorIssue";
   clauseVariableLst[45] = "starterMotorIssue";
 
   clauseVariableLst[49] = "pedal";           // 4
   clauseVariableLst[53] = "pedal";
   clauseVariableLst[57] = "pedalIssue";
   clauseVariableLst[61] = "pedalIssue";
   
   clauseVariableLst[65] = "speaker";           // 1
   clauseVariableLst[69] = "speaker";
   clauseVariableLst[73] = "speakerIssue";
   clauseVariableLst[77] = "speakerIssue";
   
   clauseVariableLst[81] = "door";           // 1
   clauseVariableLst[85] = "door";
   clauseVariableLst[89] = "doorIssue";
   clauseVariableLst[93] = "doorIssue";
   
   clauseVariableLst[97] = "strWh";           // 1
   clauseVariableLst[101] = "strWh";
   clauseVariableLst[105] = "strWhIssue";
   clauseVariableLst[109] = "strWhIssue";
   
   clauseVariableLst[113] = "fuleInj";           // 1
   clauseVariableLst[117] = "fuleInj";
   clauseVariableLst[121] = "fuleInjIssue";
   clauseVariableLst[125] = "fuleInjIssue";
   
   clauseVariableLst[129] = "fulePump";           // 1
   clauseVariableLst[133] = "fulePump";
   clauseVariableLst[137] = "fulePumpIssue";
   clauseVariableLst[141] = "fulePumpIssue";
   
   clauseVariableLst[145] = "fuleFtr";           // 1
   clauseVariableLst[149] = "fuleFtr";
   clauseVariableLst[153] = "fuleFtrIssue";
   clauseVariableLst[157] = "fuleFtrIssue";
   
   clauseVariableLst[161] = "gasTankEm";           // 1
   clauseVariableLst[165] = "gasTankEm";
   clauseVariableLst[169] = "gasTankEmIssue";
   clauseVariableLst[173] = "gasTankEmIssue";
   
   clauseVariableLst[177] = "sensor";           // 1
   clauseVariableLst[181] = "sensor";
   clauseVariableLst[185] = "sensorIssue";
   clauseVariableLst[189] = "sensorIssue";
   
   clauseVariableLst[193] = "waterPump";           // 1
   clauseVariableLst[197] = "waterPump";
   clauseVariableLst[201] = "waterPumpIssue";
   clauseVariableLst[205] = "waterPumpIssue";
   
   clauseVariableLst[209] = "serpBlt";           // 1
   clauseVariableLst[213] = "serpBlt";
   clauseVariableLst[217] = "serpBltIssue";
   clauseVariableLst[221] = "serpBltIssue";
   
   clauseVariableLst[225] = "ignCo";           // 1
   clauseVariableLst[229] = "ignCo";
   clauseVariableLst[233] = "ignCoIssue";
   clauseVariableLst[237] = "ignCoIssue";
   
   clauseVariableLst[241] = "distCap";           // 1
   clauseVariableLst[245] = "distCap";
   clauseVariableLst[249] = "distCapIssue";
   clauseVariableLst[253] = "distCapIssue";
   
   clauseVariableLst[257] = "alignment";           //
   clauseVariableLst[261] = "alighment";
   clauseVariableLst[265] = "alignmentIssue";;
   clauseVariableLst[269] = "alignmentIssue";
   
   clauseVariableLst[273] = "airCon";           // 18
   clauseVariableLst[277] = "airCon";
   clauseVariableLst[281] = "airConIssue";
   clauseVariableLst[285] = "airConIssue";

   clauseVariableLst[289] = "gear";              //
   clauseVariableLst[293] = "gear";
   clauseVariableLst[297] = "gearIssue";
   clauseVariableLst[301] = "gearIssue";
   
   clauseVariableLst[305] = "brk";                //20
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
                                  cout <<"YOUR ALTERNATOR IS THE ISSUE\n";
                                  conditionVariable = alternatorIssue;
                                  break;

                          case 6: (baissue= "YES");
                                  cout <<"YOUR BATTEY IS THE ISSUE\n";

                                  conditionVariable = batteryIssue;
                                  break;


                        case 7:  (engissue= "YES");
                                  cout <<"YOUR START MOTOR IS THE ISSUE\n";
                                  conditionVariable = starterMotorIssue;
                                  break;

                          case 8: (engissue= "YES");
                                  cout <<"YOUR IGNITION COIL IS THE ISSUE\n";
                                 conditionVariable = ignCoIssue;
                                  break;

                        case 9:(engissue= "YES");
                                  cout <<"YOUR DIST CAP IS THE ISSUE\n";
                                 conditionVariable = distCapIssue;
                                  break;

                        case 10: (engissue= "YES");
                                  cout <<"AN EMPTY GAS TANK IS YOUR ISSUE\n";
                                 conditionVariable = gasTankEmIssue;
                                  break;

                        case 11: (engissue= "YES");
                                  cout <<" THE FUEL FILTER IS THE ISSUE\n";
                                    conditionVariable = fuleFtrIssue;
                                  break;

                        case 12: (engissue= "YES");
                                cout <<"THE FUEL PUMP IS THE ISSUE\n";
                                 conditionVariable = fulePumpIssue;
                                break;

                        case 13: (engissue= "YES");
                                cout <<"THE FUEL INJECTOR IS THE ISSUE\n";
                                 conditionVariable = fuleInjIssue;
                                break;

                         case 14: (oi= "YES");
                                cout <<"THE ISSUE IS NOT UNDER THE HOOD\n";
                                break;

                            case 15: (uh= "YES");
                                cout <<"THE ISSUE IS UNDER THE HOOD\n";
                                break;


                     case 16: (otheri= "YES");
                                cout <<"SERPENTIN BELT IS THE ISSUE\n";
                                 conditionVariable = serpBltIssue;
                                break;

                    case 17: (otheri= "YES");
                                cout <<"THE SENSOR IS BROKE\n";
                                 conditionVariable = sensorIssue;
                                break;

                          case 18: (issueo= "YES");
                                cout <<"THE WATER PUMP IS THE ISSUE\n";
                              conditionVariable = waterPumpIssue;
                                break;

                         case 19: (issueo= "YES");
                                cout <<"THE SENSOR IS BROKE\n";
                                 conditionVariable = sensorIssue;
                                break;

                     case 20: (crissue= "YES");
                                cout <<"THE GAS TANK IS EMPTY\n";
                                 conditionVariable = gasTankEmIssue;
                                break;

                    case 21: (crissue= "YES");
                                cout <<"THE FUEL FILTER IS THE ISSUE\n";
                                 conditionVariable = fuleFtrIssue;
                                break;

                    case 22: (crissue= "YES");
                                cout <<"THE FUEL PUMP IS THE ISSUE\n";
                                 conditionVariable = fulePumpIssue;
                                break;

                    case 23: (crissue= "YES");
                                cout <<"THE FUEL INJECTOR IS THE ISSUE\n";
                                 conditionVariable = fuleInjIssue;
                                break;

                    case 24: (interiori = "YES");
                            cout <<"THE ALLIGHNMENT OF THE CAR IS THE ISSUE\n";
                           conditionVariable = alignmentIssue;
                            break;
                      case 25: (interiori = "YES");
                                cout <<"THE AC IS THE ISSUE\n";
                                 conditionVariable = airConIssue;
                                break;

                      case 26: (interiori = "YES");
                                cout <<"THE STEERING WHEEL IS THE ISSUE\n";
                                 conditionVariable = strWhIssue;
                                break;

                      case 27: (interiori = "YES");
                                cout <<"THE DOOR IS THE ISSUE\n";
                               conditionVariable = doorIssue;
                                break;

                      case 28: (interiori = "YES");
                                cout <<"THE GEAR SHIFT IS THE ISSUE\n";
                                 conditionVariable = gearIssue;
                                break;

                      case 29: (interiori = "YES");
                                cout <<"THE SPEAKERS ARE THE ISSUE\n";
                                 conditionVariable = speakerIssue;
                                break;

                      case 30: (interiori = "YES");
                                cout <<"THE PEDAL IS THE ISSUE\n";
                              conditionVariable = pedalIssue;
                                break;

                     case 31: (interiori = "YES");
                                cout <<"THE BRAKE IS THE ISSUE\n";
                                 conditionVariable = brkIssue;
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
                 
                  case 1: if(battery2 == "no") {setVal = 1;} break;
                  case 2: if(battery2 == "yes") {setVal = 1;} break;
                  case 3: if(batteryIssue == "yes") {setVal = 1;} break;
                  case 4: if(batteryIssue == "no"){setVal = 1;} break;
                     
                  case 5: if(alternator2 == "no") {setVal = 1;} break;
                  case 6: if(alternator2 == "yes") {setVal = 1;} break;
                  case 7: if(alternatorIssue == "yes") {setVal = 1;} break;
                  case 8: if(alternatorIssue == "no"){setVal = 1;} break;
                     
                  case 9: if(starterMotor2 == "no") {setVal = 1;} break;
                  case 10: if(starterMotor2 == "yes") {setVal = 1;} break;
                  case 11: if(starterMotorIssue == "yes") {setVal = 1;} break;
                  case 12: if(starterMotorIssue == "no"){setVal = 1;} break;
                     
                  case 13: if(pedal2 == "no") {setVal = 1;} break;
                  case 14: if(pedal2 == "yes") {setVal = 1;} break;
                  case 15: if(pedalIssue == "yes") {setVal = 1;} break;
                  case 16: if(pedalIssue == "no"){setVal = 1;} break;
                     
                  case 17: if(speaker2 == "no") {setVal = 1;} break;
                  case 18: if(speaker2 == "yes") {setVal = 1;} break;
                  case 19: if(speakerIssue == "yes") {setVal = 1;} break;
                  case 20: if(speakerIssue == "no"){setVal = 1;} break;
                     
                  case 21: if(door2 == "no") {setVal = 1;} break;
                  case 22: if(door2 == "yes") {setVal = 1;} break;
                  case 23: if(doorIssue == "yes") {setVal = 1;} break;
                  case 24: if(doorIssue == "no"){setVal = 1;} break;
                     
                  case 25:if(strWh2 == "no") {setVal = 1;} break;
                  case 26:if(strWh2 == "yes") {setVal = 1;} break;
                  case 27:if(strWhIssue == "yes") {setVal = 1;} break;
                  case 28:if(strWhIssue == "no") {setVal = 1;} break;
                    
                  case 29:if(fuleInj2 == "no") {setVal = 1;} break;
                  case 30:if(fuleInj2 == "yes") {setVal = 1;} break;
                  case 31:if(fuleInjIssue == "yes") {setVal = 1;} break;
                  case 32:if(fuleInjIssue == "no") {setVal = 1;} break;
                     
                  case 33:if(fulePump2 == "no") {setVal = 1;} break;
                  case 34:if(fulePump2 == "yes") {setVal = 1;} break;
                  case 35:if(fulePumpIssue == "yes") {setVal = 1;} break;
                  case 36:if(fulePumpIssue == "no") {setVal = 1;} break;
                    
                  case 37:if(fuleFtr2 == "no") {setVal = 1;} break;
                  case 38:if(fuleFtr2 == "yes") {setVal = 1;} break;
                  case 39:if(fuleFtrIssue == "yes") {setVal = 1;} break;
                  case 40:if(fuleFtrIssue == "no") {setVal = 1;} break;
                     
                  case 41:if(gasTankEm2 == "no") {setVal = 1;} break;
                  case 42:if(gasTankEm2 == "yes") {setVal = 1;} break;
                  case 43:if(gasTankEmIssue == "yes") {setVal = 1;} break;
                  case 44:if(gasTankEmIssue == "no") {setVal = 1;} break;

                  case 45:if(sensor2 == "no") {setVal = 1;} break;
                  case 46:if(sensor2 == "yes") {setVal = 1;} break;
                  case 47:if(sensorIssue == "yes") {setVal = 1;} break;
                  case 48:if(sensorIssue == "no") {setVal = 1;} break;
                    
                  case 49:if(waterPump2 == "no") {setVal = 1;} break;
                  case 50:if(waterPump2 == "yes") {setVal = 1;} break;
                  case 51:if(waterPumpIssue == "yes") {setVal = 1;} break;
                  case 52:if(waterPumpIssue == "no") {setVal = 1;} break;
                     
                  case 53:if(serpBlt2 == "no") {setVal = 1;} break;
                  case 54:if(serpBlt2 == "yes") {setVal = 1;} break;
                  case 55:if(serpBltIssue == "yes") {setVal = 1;} break;
                  case 56:if(serpBltIssue == "no") {setVal = 1;} break;
                    
                  case 57:if(ignCo2 == "no") {setVal = 1;} break;
                  case 58:if(ignCo2 == "yes") {setVal = 1;} break;
                  case 59:if(ignCoIssue == "yes") {setVal = 1;} break;
                  case 60:if(ignCoIssue == "no") {setVal = 1;} break;
                     
                  case 61:if(distCap2 == "no") {setVal = 1;} break;
                  case 62:if(distCap2 == "yes") {setVal = 1;} break;
                  case 63:if(distCapIssue == "yes") {setVal = 1;} break;
                  case 64:if(distCapIssue == "no") {setVal = 1;} break;
                     
                  case 65:if(alignment2 == "no") {setVal = 1;} break;
                  case 66:if(alignment2 == "yes") {setVal = 1;} break;
                  case 67:if(alignmentIssue == "yes") {setVal = 1;} break;
                  case 68:if(alignmentIssue == "no") {setVal = 1;} break;
                     
                  case 69:if(airCon2 == "no") {setVal = 1;} break;
                  case 70:if(airCon2 == "yes") {setVal = 1;} break;
                  case 71:if(airConIssue == "yes") {setVal = 1;} break;
                  case 72:if(airConIssue == "no") {setVal = 1;} break;
                     
                  case 73:if(gear2 == "no") {setVal = 1;} break;
                  case 74:if(gear2 == "yes") {setVal = 1;} break;
                  case 75:if(gearIssue == "yes") {setVal = 1;} break;
                  case 76:if(gearIssue == "no") {setVal = 1;} break;
                     
                  case 77:if(brk2 == "no") {setVal = 1;} break;
                  case 78:if(brk2 == "yes") {setVal = 1;} break;
                  case 79:if(brkIssue == "yes") {setVal = 1;} break;
                  case 80:if(brkIssue == "no") {setVal = 1;} break;

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
                  battRepair = "no";
                  std::cout <<  "REPAIR: THE BATTERY WILL HAVE TO BE REPLACED\n";
                  variable = "battRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 2:
                  battRepair = "yes";
                  std::cout <<  "REPAIR: ADD WATER TO BATTERY\n";
                  variable = "battRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 3:
                  battery2 = "no";
                  std::cout <<"The battery cannot be repaired\n";
                  variable = "battery";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 4:
                  battery2 = "yes";
                  std::cout << "The battery can be repaired\n";
                  variable = "battery";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 5:
                  altRepair = "no";
                  std::cout <<  "REPAIR: THE ALTERNATOR WILL HAVE TO BE REPLACED\n";
                  variable = "altRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 6:
                  altRepair = "yes";
                  std::cout <<  "REPAIR: FIX ALTERNATOR\n";
                  variable = "altRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 7:
                  alternator2 = "no";
                  std::cout <<"The alternator cannot be repaired\n";
                  variable = "alternator";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 8:
                  alternator2 = "yes";
                  std::cout << "The alternator can be repaired\n";
                  variable = "alternator";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 9:
                  stMoRepair = "no";
                  std::cout <<  "REPAIR: THE STMO WILL HAVE TO BE REPLACED\n";
                  variable = "stMoRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 10:
                  stMoRepair = "yes";
                  std::cout <<  "REPAIR: FIX STMO\n";
                  variable = "stMoRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 11:
                  starterMotor2 = "no";
                  std::cout <<"The stmo cannot be repaired\n";
                  variable = "starterMotor";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 12:
                  starterMotor2 = "yes";
                  std::cout << "The stmo can be repaired\n";
                  variable = "starterMotor";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 13:
                  pedalRepair = "no";
                  std::cout <<  "REPAIR: THE pedal WILL HAVE TO BE REPLACED\n";
                  variable = "pedalRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 14:
                  pedalRepair = "yes";
                  std::cout <<  "REPAIR: pedal\n";
                  variable = "pedalRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 15:
                  pedal2 = "no";
                  std::cout <<"The pedal cannot be repaired\n";
                  variable = "pedal";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 16:
                  pedal2 = "yes";
                  std::cout << "The pedal can be repaired\n";
                  variable = "pedal";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 17:
                  speakerRepair = "no";
                  std::cout <<  "REPAIR: THE speaker WILL HAVE TO BE REPLACED\n";
                  variable = "speakerRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 18:
                  speakerRepair = "yes";
                  std::cout <<  "REPAIR: FIX speaker\n";
                  variable = "speakerRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 19:
                  speaker2 = "no";
                  std::cout <<"The speaker cannot be repaired\n";
                  variable = "speaker";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 20:
                  speaker2 = "yes";
                  std::cout << "The speaker can be repaired\n";
                  variable = "speaker";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 21:
                  doorRepair = "no";
                  std::cout <<  "REPAIR: THE door WILL HAVE TO BE REPLACED\n";
                  variable = "doorRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 22:
                  doorRepair = "yes";
                  std::cout <<  "REPAIR: FIX door\n";
                  variable = "doorRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 23:
                  door2 = "no";
                  std::cout <<  "REPAIR: THE door WILL HAVE TO BE REPLACED\n";
                  variable = "door";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 24:
                  door2 = "yes";
                  std::cout <<  "REPAIR: FIX door\n";
                  variable = "door";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 25:
                  strWhRepair = "no";
                  std::cout <<  "REPAIR: THE strWh WILL HAVE TO BE REPLACED\n";
                  variable = "strWhRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 26:
                  strWhRepair = "yes";
                  std::cout <<  "REPAIR: FIX strWh\n";
                  variable = "strWhRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 27:
                  strWh2 = "no";
                  std::cout <<"The strWh cannot be repaired\n";
                  variable = "strWh";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 28:
                  strWh2 = "yes";
                  std::cout << "The strWh can be repaired\n";
                  variable = "strWh";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 29:
                  fuleInjRepair = "no";
                  std::cout <<  "REPAIR: THE fuleInj WILL HAVE TO BE REPLACED\n";
                  variable = "fuleInjRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 30:
                  fuleInjRepair = "yes";
                  std::cout <<  "REPAIR: FIX fuleInj\n";
                  variable = "fuleInjRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 31:
                  fuleInj2 = "no";
                  std::cout <<"The fuleInj cannot be repaired\n";
                  variable = "fuleInj";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 32:
                  fuleInj2 = "yes";
                  std::cout << "The fuleInj can be repaired\n";
                  variable = "fuleInj";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 33:
                  fulePumpRepair = "no";
                  std::cout <<  "REPAIR: THE fulePump WILL HAVE TO BE REPLACED\n";
                  variable = "fulePumpRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 34:
                  fulePumpRepair = "yes";
                  std::cout <<  "REPAIR: FIX fulePump\n";
                  variable = "fulePumpRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 35:
                  fulePump2 = "no";
                  std::cout <<"The fulePump cannot be repaired\n";
                  variable = "fulePump";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 36:
                  fulePump2 = "yes";
                  std::cout << "The fulePump can be repaired\n";
                  variable = "fulePump";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 37:
                  fuleFtrRepair = "no";
                  std::cout <<  "REPAIR: THE fuleFtr WILL HAVE TO BE REPLACED\n";
                  variable = "fuleFtrRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 38:
                  fuleFtrRepair = "yes";
                  std::cout <<  "REPAIR: fuleFtr\n";
                  variable = "fuleFtrRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 39:
                  fuleFtr2 = "no";
                  std::cout <<"The fuleFtr cannot be repaired\n";
                  variable = "fuleFtr";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 40:
                  fuleFtr2 = "yes";
                  std::cout << "The fuleFtr can be repaired\n";
                  variable = "fuleFtr";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 41:
                  gasTankEmRepair = "no";
                  std::cout <<  "REPAIR: THE gasTankEm WILL HAVE TO BE REPLACED\n";
                  variable = "gasTankEmRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 42:
                  gasTankEmRepair = "yes";
                  std::cout <<  "REPAIR: FIX gasTankEm\n";
                  variable = "gasTankEmRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 43:
                  gasTankEm2 = "no";
                  std::cout <<"The gasTankEm cannot be repaired\n";
                  variable = "gasTankEm";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 44:
                  gasTankEm2 = "yes";
                  std::cout << "The gasTankEm can be repaired\n";
                  variable = "gasTankEm";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 45:
                  sensorRepair = "no";
                  std::cout <<  "REPAIR: THE sensor WILL HAVE TO BE REPLACED\n";
                  variable = "sensorRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 46:
                  sensorRepair = "yes";
                  std::cout <<  "REPAIR: FIX sensor\n";
                  variable = "sensorRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 47:
                  sensor2 = "no";
                  std::cout <<  "REPAIR: THE sensor WILL HAVE TO BE REPLACED\n";
                  variable = "sensor";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 48:
                  sensor2 = "yes";
                  std::cout <<  "REPAIR: FIX sensor\n";
                  variable = "sensor";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 49:
                  waterPumpRepair = "no";
                  std::cout <<  "REPAIR: THE waterPump WILL HAVE TO BE REPLACED\n";
                  variable = "waterPumpRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 50:
                  waterPumpRepair = "yes";
                  std::cout <<  "REPAIR: FIX waterPump\n";
                  variable = "waterPumpRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 51:
                  waterPump2 = "no";
                  std::cout <<"The waterPump cannot be repaired\n";
                  variable = "waterPump";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 52:
                  waterPump2 = "yes";
                  std::cout << "The waterPump can be repaired\n";
                  variable = "waterPump";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 53:
                  serpBltRepair = "no";
                  std::cout <<  "REPAIR: THE serpBlt WILL HAVE TO BE REPLACED\n";
                  variable = "serpBltRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 54:
                  serpBltRepair = "yes";
                  std::cout <<  "REPAIR: FIX serpBlt\n";
                  variable = "serpBltRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 55:
                  serpBlt2 = "no";
                  std::cout <<"The serpBlt cannot be repaired\n";
                  variable = "serpBlt";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 56:
                  serpBlt2 = "yes";
                  std::cout << "The serpBlt can be repaired\n";
                  variable = "serpBlt";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 57:
                  ignCoRepair = "no";
                  std::cout <<  "REPAIR: THE ignCo WILL HAVE TO BE REPLACED\n";
                  variable = "ignCoRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 58:
                  ignCoRepair = "yes";
                  std::cout <<  "REPAIR: FIX ignCo\n";
                  variable = "ignCoRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 59:
                  ignCo2 = "no";
                  std::cout <<"The ignCo cannot be repaired\n";
                  variable = "ignCo";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 60:
                  ignCo2 = "yes";
                  std::cout << "The ignCo can be repaired\n";
                  variable = "ignCo";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 61:
                  distCapRepair = "no";
                  std::cout <<  "REPAIR: THE distCap WILL HAVE TO BE REPLACED\n";
                  variable = "distCapRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 62:
                  distCapRepair = "yes";
                  std::cout <<  "REPAIR: distCap\n";
                  variable = "distCapRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 63:
                  distCap2 = "no";
                  std::cout <<"The distCap cannot be repaired\n";
                  variable = "distCap";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 64:
                  distCap2 = "yes";
                  std::cout << "The distCap can be repaired\n";
                  variable = "distCap";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 65:
                  alignmentRepair = "no";
                  std::cout <<  "REPAIR: THE ALIGNMENT WILL HAVE TO BE REPLACED\n";
                  variable = "alignmentRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 66:
                  alignmentRepair = "yes";
                  std::cout <<  "REPAIR: FIX ALIGNMENT\n";
                  variable = "alignmentRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 67:
                  alignment2 = "no";
                  std::cout <<"The ALIGNMENT cannot be repaired\n";
                  variable = "alignment";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 68:
                  alignment2 = "yes";
                  std::cout << "The ALIGNMENT can be repaired\n";
                  variable = "alignment";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 69:
                  airConRepair = "no";
                  std::cout <<  "REPAIR: THE A/C WILL HAVE TO BE REPLACED\n";
                  variable = "airConRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 70:
                  airConRepair = "yes";
                  std::cout <<  "REPAIR: FIX A/C\n";
                  variable = "airConRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 71:
                  airCon2 = "no";
                  std::cout <<"The A/C cannot be repaired\n";
                  variable = "airCon";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 72:
                  airCon2 = "yes";
                  std::cout << "The A/C can be repaired\n";
                  variable = "airCon";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 73:
                  gearRepair = "no";
                  std::cout <<  "REPAIR: THE GEAR WILL HAVE TO BE REPLACED\n";
                  variable = "gearRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 74:
                  gearRepair = "yes";
                  std::cout <<  "REPAIR: FIX GEAR\n";
                  variable = "gearRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 75:
                  gear2 = "no";
                  std::cout <<   "The GEAR cannot be repaired\n";
                  variable = "gear";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 76:
                  gear2 = "yes";
                  std::cout <<   "The GEAR can be repaired\n";
                  variable = "gear";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 77:
                  brkRepair = "no";
                  std::cout <<  "REPAIR: THE BREAKS WILL HAVE TO BE REPLACED\n";
                  variable = "brkRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 78:
                  brkRepair = "yes";
                  std::cout <<  "REPAIR: FIX BREAKS\n";
                  variable = "brkRepair";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 79:
                  brk2 = "no";
                  std::cout <<  "The BREAKS cannot be repaired\n";
                  variable = "brk";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               case 80:
                  brk2 = "yes";
                  std::cout <<  "The BREAKS can be repaired\n";
                  variable = "brk";
                  instantiate(variable,variableLst,conclutionQueue,instlt2,backPtr);
                  break;
               default:
                  break;
            }
            firstStm = statmentNum + 1;
            flag = false;
         }
      }          /*  <--------------------------------------    End of loop 2 */
      frontPtr++;
      if(frontPtr < backPtr){
         firstStm = 1;
         flag = false;
      }
      else
         flag = true;
   }            /*  <--------------------------------------     End of loop 3 */
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
<>                  <>
<>                  <>
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><> */

void search(string* cVL, string* cQ, int& cn, int& sn, int& fp,int& fs){
   bool flag = true;
   int k;
   sn = fs;
   while(flag == true && sn < 81){  // sn needs to reach the clause number ex: sn < 13 = clause 12
      cn = 1;                       // sn < 448 <-- for all 30
      k = 4 * (sn - 1) + cn;
//      std::cout << cVL[k] <<" "<< cQ[fp] <<" = k search   \n";
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
<>                            <>
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
            std::cout << "Is the battery maintenance free? (yes or no):  ";
            std::cin>> batt;
            break;
         case 2:
            std::cout << "Is the alternator broken? (yes or no) ";
            std::cin>> alt;
            break;
         case 3:
            std::cout << "Is the starter motor broken? (yes or no) ";
            std::cin>> stmo;
            break;
         case 4:
            std::cout << "Is the pedal broken? (yes or no): ";
            std::cin>> ped;
            break;
         case 5:
            std::cout << "Is the speaker broken? (yes or no): ";
            std::cin>> spk;
            break;
         case 6:
            std::cout << "Is the door broken? (yes or no):  ";
            std::cin>> dr;
            break;
         case 7:
            std::cout << "Is the steer broken?(yes or no) ";
            std::cin>> sw;
            break;
         case 8:
            std::cout << "Is the fuleinj motor broken?(yes or no) ";
            std::cin>> fI;
            break;
         case 9:
            std::cout << "Is the fulepump broken? (yes or no): ";
            std::cin>> fP;
            break;
         case 10:
            std::cout << "Is the fulefilter broken? (yes or no): ";
            std::cin>> fF;
            break;
         case 11:
            std::cout << "Is the gastank free? (yes or no):  ";
            std::cin>> gT;
            break;
         case 12:
            std::cout << "Is the sensor broken? (yes or no) ";
            std::cin>> s;
            break;
         case 13:
            std::cout << "Is the waterpump  broken? (yes or no) ";
            std::cin>> wP;
            break;
         case 14:
            std::cout << "Is the serpB broken? (yes or no): ";
            std::cin>> sB;
            break;
         case 15:
            std::cout << "Is the ingnitioncoil broken? (yes or no): ";
            std::cin>> iG;
            break;
         case 16:
            std::cout << "Is the distributer cap broken? (yes or no):  ";
            std::cin>> dC;
            break;
         case 17:
            std::cout << "Is the alignment bad?(yes or no) ";
            std::cin>> aM;
            break;
         case 18:
            std::cout << "Is the A/C bad?(yes or no) ";
            std::cin>> aC;
            break;
         case 19:
            std::cout << "Is the Gear broken?(yes or no) ";
            std::cin>> g;
            break;
         case 20:
            std::cout << "Are the Breaks bad ?(yes or no) ";
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
