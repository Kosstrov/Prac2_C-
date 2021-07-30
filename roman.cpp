/**
 * Computer Programming 2 (COMP2711, COMP8801)
 * Practical 2: Roman Numbers
 */

#include <iostream>
#include <cctype>
using namespace std;


int main(int argc, char *argv[])
{
    const string romans = "IVXLCDM";
    const string arabic = "0123456789";
    const string units[]={"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    const string tens[]={"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    const string hundreds[]={"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
    const string thousands[]={"", "M", "MM", "MMM", "","","","","","" };
    string inp;
    int i, j , k , l;


    while(!cin.eof()){
        cin >> inp;


        if(cin.good()){
            for (int r = 0; r < inp.length(); r++) {
                inp[r] = toupper(inp[r]);
            }

            string out="";
            int total = 0;
            int tho = 0;
            int hun = 0;
            int ten = 0;
            int uni = 0;
            bool flag1 = false;


    size_t found = inp.find_first_of(romans);
    while (found!=string::npos)
    {

        if((tho==0)&&(hun==0)&&(ten==0)&&(uni==0)){
            if(inp[0]!=inp[found]){
            //cout << total << endl;
            break;
            }
        }

        for(int a =4;a>0;a--){

            for(l=9;l>=0;l--){
                if(inp.substr(found,a)==thousands[l]){
                    if(tho==0){
                        inp.replace(found,a,"*");
                        //cout << "found" << endl;
                        tho+=1000*l;
                        break;
                    }
                }
            }

                for(k=9;k>=0;k--){
                    if(inp.substr(found,a)==hundreds[k]){
                        if(hun==0){
                            inp.replace(found,a,"*");
                            //cout << "found" << endl;
                            hun+=100*k;
                            break;
                        }
                    }
                }


                for(j=9;j>=0;j--){
                    if(inp.substr(found,a)==tens[j]){
                        if(ten==0){
                            inp.replace(found,a,"*");
                            ten+=10*j;
                            break;
                        }
                    }
                }


                for(i=9;i>=0;i--){
                    if(inp.substr(found,a)==units[i]){
                        if(uni==0){
                            inp.replace(found,a,"*");
                            uni+=i;
                            break;
                        }
                    }
                }

        }

        for(int w = 0;w<romans.length();w++ ){
            if(inp[found+1]==romans[w]){
                flag1=true;
            }
        }

        if(flag1){
            found=inp.find_first_of(romans,found+1);
        } else {
            break;
        }

    }

    size_t found2 = inp.find_first_of(arabic);
    if (found2!=string::npos){
        size_t sz;
        int inp1 = stoi(inp,&sz);
        if(inp1>0){
            if(inp1>=10){
                if(inp1>=100){
                    if(inp1>=1000){
                        int a = (inp1-(inp1%1000))/1000;
                        out+=thousands[a];
                        inp1-=(inp1-(inp1%1000));
                    }
                    int a = (inp1-(inp1%100))/100;
                    out+=hundreds[a];
                    inp1-=(inp1-(inp1%100));
                }
                int a = (inp1-(inp1%10))/10;
                out+=tens[a];
                inp1-=(inp1-(inp1%10));
            }
            out+=units[inp1];
        }
    }

            total = tho + hun + ten + uni;
            if(!out.empty()){
                cout << out << endl;
            } else {
                cout << total << endl;
            }
        }
    }


    return 0;

}


