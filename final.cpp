#include<iostream>
#include<vector>
#include<string>
#include<windows.h> 
#include<math.h>
#include<fstream> 
#include<cwchar> //font
#include<unistd.h> //delay
using namespace std;

const char rocketR[] =
"                                                            |\n\
                                                             ^\n\
                                                            /^\\\n\
                                                            | |\n\
                                                            | |\n\
                                                            |R|\n\
                                                            |E|\n\
                                                            |D|\n\
                                                            | |\n\
                                                           /| |\\\n\
                                                          /^| |^\\\n\
                                                         |((| |))|\n\
                                                          `-\"\#\"-`\n\
                                                             *\n\
" 
;
const char rocketB[] =
"                                                            |\n\
                                                             ^\n\
                                                            /^\\\n\
                                                            | |\n\
                                                            | |\n\
                                                            |B|\n\
                                                            |L|\n\
                                                            |U|\n\
                                                            |E|\n\
                                                           /| |\\\n\
                                                          /^| |^\\\n\
                                                         |((| |))|\n\
                                                          `-\"\#\"-`\n\
                                                             *\n\
" 
;
string table1[3][3]={"#","#","#","#","#","#","#","#","#"};
string table2[3][3]={"#","#","#","#","#","#","#","#","#"};
string table3[3][3]={"#","#","#","#","#","#","#","#","#"};
int rm[6]={1,1,1,1,1,1};
int bm[6]={1,1,1,1,1,1};
int winner;
int first_player_have_changed;

void moshak(char c){
	if(c=='R'){
			system("color 40");
  for (int i = 0; i < 65; i ++) printf("\n");
  printf("%s", rocketR);
  int j = 300000   ;
  for (int i = 0; i < 100; i ++) {
         usleep(j);
         j = (int)(j * 0.8); //speed
 printf("\n");
}
}
else{
	system("color 30");
  for (int i = 0; i < 65; i ++) printf("\n");
  printf("%s", rocketB);
  int j = 300000   ;
  for (int i = 0; i < 100; i ++) {
         usleep(j);
         j = (int)(j * 0.8); //speed
 printf("\n");	
}
}
}
string akhar(int a,int b){
	if(table3[a][b]!="#"){
		return table3[a][b];
	}
	if(table2[a][b]!="#"){
		return table2[a][b];
	}
	if(table1[a][b]!="#"){
		return table1[a][b];
	}
	return "#";
}
void chap(){
	cout<<"\t\t player RED:  ";
	for(int i=0;i<6;i++){
		if(rm[i]==1){
			cout<<"R"<<ceil(i/2)+1;
			cout<<" ";
		}
	}
	cout<<endl<<"\t\t player BLUE: ";
	for(int i=0;i<6;i++){
		if(bm[i]==1){
			cout<<"B"<<ceil(i/2)+1;
			cout<<" ";
		}
	}
	cout<<endl;
	for(int i=0;i<3;i++){
		cout<<"\t\t\t\t ";
		for(int j=0;j<3;j++){
			cout<<""<<akhar(i,j);
			cout<<" ";
		}
		cout<<endl;
	}
	cout<<"\t\t__________________________________________"<<endl;
}
void mohre(char c){
	inja:
	if(c=='R'){
		cout<<"\t\tplayer RED ";
	}	
	else{
		cout<<"\t\tplayer BLUE ";
	}
	cout<<"\t\tplease enter your piece's value:"<<endl;
	string s;
	cin>>s;
	
	if(c=='R'){
		int k=2*(s[1]-'0')-1;
		if(rm[k]==0 && rm[k-1]==0){
			cout<<"you dont have this piece try again"<<endl;
			goto inja;
		}		
	}
	if(c=='B'){
		int k=2*(s[1]-'0')-1;
		if(bm[k]==0 && bm[k-1]==0){
			cout<<"you dont have this piece try again"<<endl;
			goto inja;
		}		
	}	
	
	if(s[0]!=c){
		cout<<"choose one of your pieces, again:"<<endl;
		goto inja;
	}
	if(s[1]-'0'>3){
		cout<<"you dont have this piece, try again:"<<endl;
		goto inja;
	}
	int a,b;
	cout<<"enter the coordination:"<<endl;
	cin>>a>>b;
	if(a<=0 || a>3 || b<=0 || b>3){
		cout<<"this coordination doesnt exist, try again:"<<endl;
		goto inja;
	}
	a--; b--;
	if(s[1]==1+'0'){
		if(table1[a][b]!="#" || table2[a][b]!="#" || table3[a][b]!="#"){
			cout<<"wrong move try again"<<endl;
			goto inja;
		}		
		table1[a][b]=s;
	}
	else if(s[1]==2+'0'){
		if(table2[a][b]!="#" || table3[a][b]!="#"){
			cout<<"wrong move try again"<<endl;
			goto inja;
		}				
		table2[a][b]=s;
	}
	else if(s[1]==3+'0'){
		if(table3[a][b]!="#"){
			cout<<"wrong move try again"<<endl;
			goto inja;
		}		
		table3[a][b]=s;
	}	
	if(c=='R'){
		int k=2*(s[1]-'0')-1;
		if(rm[k]!=0){
			rm[k]=0;
		}	
		else if(rm[k]==0){
			rm[k-1]=0;
			}
	}		
	else{
		int k=2*(s[1]-'0')-1;
		if(bm[k]!=0){
			bm[k]=0;
		}	
		else if(bm[k]==0){
			bm[k-1]=0;
		}			
	}
}
bool tamam(char c){
	if((akhar(0,0)[0]==akhar(1,1)[0] && akhar(1,1)[0]==akhar(2,2)[0] && akhar(1,1)[0]==c))
		return true;
	if((akhar(0,0)[0]==akhar(1,0)[0] && akhar(1,0)[0]==akhar(2,0)[0] && akhar(1,0)[0]==c))
		return true;
	if((akhar(0,1)[0]==akhar(1,1)[0] && akhar(1,1)[0]==akhar(2,1)[0] && akhar(1,1)[0]==c))
		return true;					
	if((akhar(2,0)[0]==akhar(1,2)[0] && akhar(1,2)[0]==akhar(2,2)[0] && akhar(1,2)[0]==c))
		return true;
	if((akhar(0,0)[0]==akhar(0,1)[0] && akhar(0,1)[0]==akhar(0,2)[0] && akhar(0,1)[0]==c))
		return true;
	if((akhar(1,0)[0]==akhar(1,1)[0] && akhar(1,1)[0]==akhar(1,2)[0] && akhar(1,1)[0]==c))
		return true;
	if((akhar(2,0)[0]==akhar(2,1)[0] && akhar(2,1)[0]==akhar(2,2)[0] && akhar(2,1)[0]==c))
		return true;
	if((akhar(2,0)[0]==akhar(1,1)[0] && akhar(1,1)[0]==akhar(0,2)[0] && akhar(1,1)[0]==c))
		return true;
	return false;
}
void change(char c){
	baz:
	int a,b;
	cout<<"enter coordination of your piece which you want to move"<<endl;
	cin>>a>>b;
	a--;b--;
	if(akhar(a,b)[0]!=c){
		cout<<"choose one of YOUR pieces, if you still want to move your piece enter 1 otherwise Want to enter new piece enter 2"<<endl;
		int t;
		cin>>t;
		if(t==1)
			goto baz;
		else{
			mohre(c);
			return;
		}
	}
	int aa,bb;
	cout<<"enter new coordintion"<<endl;
	cin>>aa>>bb;
	aa--;bb--;
	//--------
	if(akhar(aa,bb)=="#"){
		if(akhar(a,b)[1]=='1'){
			table1[aa][bb]=akhar(a,b);
			table1[a][b]="#";
		}
		else if(akhar(a,b)[1]=='2'){
			table2[aa][bb]=akhar(a,b);
			table2[a][b]="#";
		}	
		else if(akhar(a,b)[1]=='3'){
			table3[aa][bb]=akhar(a,b);
			table3[a][b]="#";
		}
		return;			
	}
	if(akhar(aa,bb)[1]=='1'){
		if(akhar(a,b)[1]=='1'){
			cout<<"wrong move try again"<<endl;
			goto baz;
		}
		else if(akhar(a,b)[1]=='2'){
			table2[aa][bb]=akhar(a,b);
			table2[a][b]="#";
		}	
		else if(akhar(a,b)[1]=='3'){
			table3[aa][bb]=akhar(a,b);
			table3[a][b]="#";
		}	
		return;		
	}	
	if(akhar(aa,bb)[1]=='2'){
		if(akhar(a,b)[1]=='1'){
			cout<<"wronG move try again"<<endl;
			goto baz;
		}
		else if(akhar(a,b)[1]=='2'){
			cout<<"wronG move try again "<<endl;
			goto baz;
		}	
		else if(akhar(a,b)[1]=='3'){
			table3[aa][bb]=akhar(a,b);
			table3[a][b]="#";
		}	
		return;		
	}
	if(akhar(aa,bb)[1]=='3'){
		cout<<"wrong move try again"<<endl;
		goto baz;
	}
}
void file(string name1,string name2){
	string line;
	int is_both_in=0;
	vector<string>v;
	string win1, win2;
	fstream data;
	data.open("data.txt",ios::in);
	while(getline(data,line)){
		string s="";
		line+=" ";
		for(int j=0;j<line.size();j++){
			if(line[j]==' '){
				v.push_back(s);
				s="";
			}	
			else{
				s+=line[j];
			}
		}
		for(int i=0;i<v.size();i++){
			if(v[i]==name1){
				is_both_in++;
				win1=v[i+2];
			}
		}
		for(int i=0;i<v.size();i++){
			if(v[i]==name2){
				is_both_in++;
				win2=v[i+2];
			}
		}
		if(is_both_in==2){
			break;
		}
		else{
			v.clear();
			is_both_in=0;
		}
	}
	if(is_both_in==2){
		cout<<"previous games:"<<endl<<name1<<": "<<win1<<endl<<name2<<": "<<win2<<endl;
		if(win1+'0'>=win2+'0'){
			cout<<endl<<name1<<" must start the game as player RED"<<endl<<endl;
		}
		if(win2+'0'>win1+'0'){
			cout<<endl<<name2<<" must start the game as player RED"<<endl<<endl;
			first_player_have_changed++;
		}		
		return;
	}
	data.close();
	data.open("data.txt",ios::app);
	cout<<"there is no data from your previous games"<<endl;
	cout<<name1<<" how many times have you won against "<<name2<< "?"<<endl;
	string w1; cin>>w1;
	cout<<name2<<" how many times have you won against "<<name1<< "?"<<endl;
	string w2; cin>>w2;
	data<<name1<<" : "<<w1<<" / "<<name2<<" : "<<w2<<endl<<"_____________"<<endl;
	data.close(); 
	if(w1+'0'>=w2+'0'){
		cout<<endl<<name1<<" must start the game as player RED"<<endl<<endl;
	}
	if(w2+'0'>w1+'0'){
		cout<<endl<<name2<<" must start the game as player RED"<<endl<<endl;
	}			
}
void file_update(string name1,string name2,int winner){
	ofstream file_out("next.txt");
	string line;
	int is_both_in=0;
	vector<string>v;
	int index_win1,index_win2;
	fstream data;
	data.open("data.txt",ios::in);
	while(getline(data,line)){
		string tempo="";
		/////// for next.txt
		string s="";
		line+=" ";
		for(int j=0;j<line.size();j++){
			if(line[j]==' '){
				v.push_back(s);
				s="";
			}	
			else{
				s+=line[j];
			}
		}
		for(int i=0;i<v.size();i++){
			index_win1+=v[i].size();
			if(i!=v.size()-1){
				index_win1++;
			}
			if(v[i]==name1){
				is_both_in++;
				break;
			}
		}
		for(int i=0;i<v.size();i++){
			index_win2+=v[i].size();
			if(i!=v.size()-1){
				index_win2++;
			}			
			if(v[i]==name2){
				is_both_in++;
				break;
			}
		}
		if(is_both_in==2){
			index_win1=line.find(name1)+name1.size()+3;
			index_win2=line.find(name2)+name2.size()+3;
			if((winner==1 && first_player_have_changed==0) || (winner==2 && first_player_have_changed==1)){		
			string win1N ,win2N;
			win2N=line[index_win2];
			win1N=(line[index_win1]-'0')+1+'0';
			tempo=name1+" : "+win1N+" / "+name2+" : "+win2N+"\n";}
			else{		
			string win1N ,win2N;
			win1N=line[index_win1];
			win2N=(line[index_win2]-'0')+1+'0';
			tempo=name1+" : "+win1N+" / "+name2+" : "+win2N+"\n";}
			}
		else{
			tempo=line+"\n";
		}
		is_both_in=0;
	file_out<<tempo;
	v.clear();
	}
	file_out.close(); data.close();
	remove("data.txt");
	rename("next.txt","data.txt");
}

int main(){
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize=sizeof(cfi);
	cfi.dwFontSize.Y=25;
	cfi.dwFontSize.X=2;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE),false,&cfi);
	cout<<"player RED welcome, please enter your name:";
	string name1,name2;
	cin>>name1;
	cout<<"player BLUE welcome, please enter your name:";	
	cin>>name2;
	file(name1,name2);
	///////////////////////////
	int zoj=0;
	while(true){
		system("color 70");		
		chap();	
		zoj++;
		if(zoj%2==1){
			system("color 74");
		}
		else{
			system("color 79");			
		}
		if(tamam('R')){
			system("color 40");
			cout<<"\t\t\t  RED WON!!";
			winner=1;
			file_update(name1,name2,winner);
			usleep(1000000);			
			moshak('R');
			return 0;			
		}
		if(tamam('B')){
			system("color 30");
			cout<<"\t\t\t  BLUE WON!!";	
			winner=2;
			file_update(name1,name2,winner);
			usleep(1000000);		
			moshak('B');
			return 0;		
		}
		if(zoj==1 || zoj==2){
			if(zoj==1){
				mohre('R');
			}
			else{
				mohre('B');
			}
		}
		else{
			if(zoj%2==1){
				en:
				string l;
				cout<<"player RED enter 1 if you want to put a piece in board or enter 2 to change one of your piece's coordination:"<<endl;
				cin>>l;
				if(l!="1" && l!="2"){
					goto en;
				}					
				if(l=="1"){
					mohre('R');
				}
				else{
				 	change('R');
				}
			}
			else{	
				en2:
				string l;
				cout<<"player BLUE enter 1 if you want to put a piece in board or enter 2 to change one of your piece's coordination:"<<endl;
				cin>>l;
				if(l!="1" && l!="2"){
					goto en2;
				}
				if(l=="1"){
					mohre('B');
				}
				else{
				 	change('B');
				}
			}			
		}
		system("cls");	
	}
}
