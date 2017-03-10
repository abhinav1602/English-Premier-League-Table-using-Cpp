#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include<string.h>
#include<string>
#include<set>
 
struct le{
char name[100];
long long p;
long long gf;
long long gd;

};
 
bool myfun(le lhs,le rhs) {
if(lhs.p!=rhs.p){
return lhs.p > rhs.p;
}
else{
if(lhs.gd!=rhs.gd)
return lhs.gd > rhs.gd;

else if(lhs.gf!=rhs.gf)
return lhs.gf > rhs.gf;

else
return strcmp(lhs.name,rhs.name)<0;
}
} 

int main() {
	int t;
	std::cin>>t;
	le a[t];
	for(int i=0;i<t;i++){
	std::cin>>a[i].name;
	a[i].p=0;
	a[i].gf=0;
	a[i].gd=0;
	}
	int m;
	std::cin>>m;
	char t1[100],t2[100];
	int s1,s2,flag=0,first,sec;
	std::multiset<std::pair<int,int> > s;
	
	for(int i=1;i<=m;i++){
	std::cin>>t1>>t2>>s1>>s2;
	flag=0;
	for(int j=0;j<t;j++){
	if(flag==2)
	{
	if(first<sec)
	s.insert(std::make_pair(first,sec));
	else
	s.insert(std::make_pair(sec,first));
	
	if(s1>s2){
	a[first].p+=2;
	a[first].gf+=s1;
	a[sec].gf+=s2;
	a[first].gd+=s1-s2;
	a[sec].gd+=s2-s1;
	}
	else if(s2>s1){
	a[sec].p+=2;
	a[first].gf+=s1;
	a[sec].gf+=s2;
	a[first].gd+=s1-s2;
	a[sec].gd+=s2-s1;
	}
	else{
	a[first].p+=1;
	a[sec].p+=1;
	a[first].gf+=s1;
	a[sec].gf+=s2;
	}
	break;
	}
	
	if(strcmp(a[j].name,t1)==0){
	first=j;
	flag++;
	}
	else if(strcmp(a[j].name,t2)==0)
	{
	sec=j;
	flag++;
	}
	if(strcmp(t1,t2)==0)
	{
	    std::cout<<"Invalid Input\n";
	    return 0;
	}
	
	}

	
	}
	std::multiset<std::pair<int,int> >::iterator it1=s.begin();
	std::multiset<std::pair<int,int> >::iterator it2=it1;
	it2++;
	std::multiset<std::pair<int,int> >::iterator it3=it2;
	it3++;
	for(it1=s.begin(); it1!=s.end()&&it2!=s.end()&&it3!=s.end(); ++it1){
     if((*it1).first==(*it2).first&&(*it1).second==(*it2).second && (*it1).first==(*it3).first&&(*it1).second==(*it3).second) 
     {
         std::cout<<"Invalid Input\n";
         return 0;
     }
     it2++;
     it3++;
     
	}
	
	std::sort(a,a+t,myfun);
	for(int i=0;i<t;i++){
	std::cout<<a[i].name<<"\n";
	}
	return 0;
} 