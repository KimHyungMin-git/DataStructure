#include <iostream>
#include <string>
using namespace std;
class s_record{
    public:
    string id;
    string name;
    double score;
    s_record(string i, string n, double s);
    s_record();
};
s_record::s_record(string i, string n, double s){
    id=i;
    name=n;
    score=s;
}
s_record::s_record(){

}
void swap(s_record &a, s_record &b){
    s_record temp("0","A",0.0);
    temp=a;
    a=b;
    b=temp;
}
void quick_sort(s_record *s, int l, int r){
    s_record pivot("0","A",0.0);
    int i,j;
    if(l>=r)
    return ;
    i=l;
    j=r+1;
    pivot=s[l];
        do{
        do{
            i++;
        }while(i<=r&&s[i].id<pivot.id);
        do{
            j--;
        }while(s[j].id>pivot.id);
        if(i<j)
    swap(s[i],s[j]);
    }while(i<j);
    swap(s[l],s[j]);
    quick_sort(s,l,j-1);
    quick_sort(s,j+1,r);
}
void heap_adjust(s_record *e, int t_root, int size){
    s_record temp;
    int parent=t_root, child=2*t_root+1;
    temp=e[t_root];
    while(child<=size){
        if(child<size&&e[child].id<e[child+1].id){
            child++;
        }
        if(temp.id>=e[child].id)
        break;
        e[parent]=e[child];
        parent=child;
        child=child*2+1;
    }
    e[parent]=temp;
}
void heap_sort(s_record *s, int nu){
    int i;
    int size=nu-1;
    s_record temp;
    for(i=(size-1)/2; i>=0; i--){
        heap_adjust(s,i,size);
    }
    for(i=size-1; i>=0; i--){
        temp = s[0];
        s[0] = s[i + 1];
        s[i + 1]=temp;
        heap_adjust(s,0,i);
    }
}
void merge(s_record a[], s_record b[], int n1, int n2, int n3, int n4){
    int i,j,k,t;
    i=n1;
    j=n3;
    k=n1;
    while(i<=n2&&j<=n4){
        if(a[i].id>=a[j].id){
            b[k++]=a[j++];
        }
        else{
            b[k++]=a[i++];
        }
    }
    if(i>n2){
        for(t=j; t<=n4; t++)
            b[t]=a[t];
    }
    else {
        for(t=i; t<=n2; t++)
        b[k+t-i]=a[t];
    }
}
void merge_pass(s_record a[], s_record b[], int n, int s){
    int i, j;
    for (i = 0; i < (n - 2 * s + 1); i += 2 * s)
    merge(a, b, i, i + s - 1, i + s, i + 2 * s - 1);
    if (i + s  <= n)
    merge(a, b, i, i + s - 1, i + s, n);
    else for (j=i; j<= n; j++)b[j] = a[j];}
void merge_sort(s_record a[], int n){
    int s = 1;
    s_record b[12];
    while (s < n) {
        merge_pass(a, b, n-1, s);
        s *= 2;
        merge_pass(b, a, n-1, s);
        s *= 2;}}

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

       //quick_sort(s_list, 0, n-1);
       //heap_sort(s_list, n);
       //merge_sort(s_list, n); 

      cout << "< The result of the sorting >" << endl;
      show_thelist(s_list, n);

      return 0;

}
