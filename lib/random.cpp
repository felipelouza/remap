#include "random.hpp"

/*******************************************************************/
int random(unsigned char* str, size_t n, int verbose){

  map<char,char> A;
  std::vector<char> V;                                                                                                                                

  for(int i=0; i<n-1;i++){
    A[str[i]] = str[i];
    V.push_back(str[i]);
  }

  std::random_device rd;
  std::mt19937 randEng(rd());
  std::shuffle(V.begin(), V.end(), randEng);
  
  vector<char>::iterator it = V.begin();
  for(auto& i: A)   {
      char ts = i.second;
      i.second = A[*it];
      A[*it] = ts;
      it++;
  }

  if(verbose){
    for(auto it=A.begin(); it!=A.end(); it++){
      std::cout<<it->first<<": "<<it->second<<endl;
    }
  }

  for(int i=0; i<n-1;i++){
    str[i] = A[str[i]];
  }   

return 0;
}

/*******************************************************************/
