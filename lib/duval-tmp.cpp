#include "duval.hpp"

vector<size_t> duval(unsigned char* str, size_t n, size_t &max){

    max =0;
    size_t i = 0;
    vector<size_t> P;
    while (i < n) {
//        cout<<"i = "<<i<<endl;
        size_t j = i + 1, k = i;
        while (j < n && str[k] <= str[j]) {
            
//            cout<<"i = "<<i<<"\tk = "<<k<<" ("<<(int)str[k]<<")"<<" j = "<<j<<" ("<<(int)str[j]<<")"<<endl;

            if (str[k] < str[j]){
              //aqui!!
              //chegou uma oportunidade de quebrar
              //
              //aqui!! if(j-i==max) ou if(j-i>=limiar)
              //str[j] = MIN-alpha para quebrar
              //
//              cout<<"***\n";
                k = i;
            }
            else{
                k++;
            }
            j++;
        }
//        cout<<"i = "<<i<<"\tk = "<<k<<" j = "<<j<<" ("<<str[j]<<")\t ==> "<<j-k<<endl;
        while (i <= k) {
            i += j - k;
            if(j-k>max) max=j-k;
            P.push_back(i);
        }
    }
    return P;
}

/*******************************************************************/

int duval_break(unsigned char* str, size_t n){

    map<char, char> M;
    for(size_t i=0; i < n-1; i++){
      M[str[i]] = str[i];
    }

    map<char, char> C(M);//copy
    auto it=C.begin();
    

    size_t max;
    duval(str, n, max);
    char min=0;

    size_t i = 0;
    while (i < n) {
        cout<<"i = "<<i<<endl;
        size_t j = i + 1, k = i;
        while (j < n && str[k] <= str[j]) {
//            cout<<"i = "<<i<<"\tk = "<<k<<" ("<<(int)str[k]<<")"<<" j = "<<j<<" ("<<(int)str[j]<<")"<<endl;
            if (str[k] < str[j]){

                if((j+1)-i==max){
//                if((j+1)-i>=1000){
/*
                  if(M[str[]] != 0){
                    it->second=str[j];
                    it++;
                  }

                  M[str[j]] = 0;

                  if(it==C.end()) break;
*/                
                  min = str[i];
                  //cout<<"***"<<endl;
                }
                k = i;
            }
            else{
                k++;
            }
            j++;
        }
        
        if(it==C.end()) break;

//        cout<<"i = "<<i<<"\tk = "<<k<<" ("<<(int)str[k]<<")"<<" j = "<<j<<" ("<<(int)str[j]<<")"<<")\t ==> "<<j-k<<endl;
        while (i <= k) {
            i += j - k;
        }
    }

    auto it2=M.begin();
    while(it!=C.end()){
      while(it2!=M.end() and it2->second==0) it2++;
      it->second = it2->second;
      it++;
      it2++;
    }

    for(pair<char,char> c: C)
      cout<<c.first<<"\t"<<c.second<<endl;
//    cout<<"min = "<<min<<endl;

    for(size_t i=0; i < n-1; i++){
//      str[i]=C[str[i]];
        if(str[i]==min) str[i]=254;
    }

    return 0;
}

