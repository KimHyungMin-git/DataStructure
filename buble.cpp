#include<iostream>
#include<string>
using namespace std;
class s_record{
    public:
    string id;
    string name;
    double score;
    s_record(string i, string n, double s);
};
s_record::s_record(string i, string n, double s){
    id=i;
    name=n;
    score=s;
}
void bubble_sort(s_record *r, int num){
    int i, j;
    s_record temp("0","A",0.0);
    for(i=0; i<num; i++){
        for(j=num-1; j>=i; j--){
            if(r[j].id>r[j+1].id){
                temp=r[j];
                r[j]=r[j+1];
                r[j+1]=temp;
            }
        }
    }
}
void insertion_sort(s_record *s, int nu){
    int i,j;
    s_record temp("0","A",0.0);
    for(i=1; i<nu; i++){
        j=i-1;
        temp=s[i];
        while(j>=0&&s[j].id>temp.id){
            s[j+1]=s[j];
            j--;
        }
        s[j+1]=temp;
    }
}
void selection_sort(s_record *s, int nu){
    int i,j,min;
    s_record temp("0","A",0.0);
    for(i=0; i<nu; i++){
        min=i;
        for(j=i+1; j<nu; j++){
            if(s[min].id>s[j].id)
            min=j;
        }
        temp=s[min];
        s[min]=s[i];
        s[i]=temp;
    }
}
void show_thelist(s_record *s, int nu){
    int i;
    for(i=0; i<nu; i++){
        cout<<s[i].id<<"/"<<s[i].name<<"/"<<s[i].score<<endl;
    }
}
int main()
{
      s_record s_list[12] = { {"21900013", "Kim ", 6.5}, {"21900136", "Lee ", 8.8 }, {"21900333", "Park", 9.2 },
                                  { "21800442", "Choi", 7.1}, {"21900375", "Ryu ", 5.4  }, {"21700248", "Cho ", 6.3 },
                 { "21700302", "Jung", 8.3}, {"21800255", "Han ", 6.9  }, {"21800369", "Kang", 6.3 },
                 { "21900401", "Yang", 9.1}, {"21800123", "Moon", 8.1  }, {"21700678", "Seo ", 7.9 } };
      int    n = 12;

       //insertion_sort(s_list, n);
       //bubble_sort(s_list, n);
       selection_sort(s_list, n);     

      cout << "< The result of the sorting >" << endl;
      show_thelist(s_list, n);

      return 0;

}
