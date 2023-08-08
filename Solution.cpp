#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
using namespace std;

struct my_struct {
  string day,time;
  int fromz,toz,fare;
};

int main() 
{
  system("cls");
  int total[7]={0,0,0,0,0,0,0}, new_total[7]={0,0,0,0,0,0,0};
  int i,j,k,no=-1,t=-1,t2=0,temp,check,hr,min,week_check=0,f_disc=0,w_fare=0,flag=0,w_temp=0,w_disc=0,final_fare_calculated=0;
  struct my_struct a[1000];
  cout<<"Enter day, timme, from zone commuter enter and to which zone commuter went (enter eof if you do not want to enter more values)  : "<<endl;
  
  for (i = 0; i < 1000; i++) 
   {
     cin>>a[i].day;
     if (a[i].day=="eof" || a[i].day=="EOF" ||a[i].day=="Eof" ) 
         break;
     else {
      cin>>a[i].time;
      cin>>a[i].fromz;
      cin>>a[i].toz;
      }
   }  
 no=i;
 for (i=0; i<no; i++)
     {
        switch (a[i].fromz) 
          {
              case 1:
                if (a[i].toz==1)
                {
                    if(a[i].day=="Monday" || "Tuesday" || "Wednesday" || "Thursday" || "Friday") 
                    {
                       hr = stoi(a[i].time.substr(0, 2));
                       min = stoi(a[i].time.substr(3, 2));
                       if (hr  >= 7 && hr <= 10 && min <= 30)
                                a[i].fare=30;
                       else if (hr >= 17 && hr <= 20 )
                                a[i].fare=30;
                       else 
                                a[i].fare=25;                 
                    }  
                    else if(a[i].day=="Saturday" || "Sunday")
                    {
                       hr = stoi(a[i].time.substr(0, 2));
                       min = stoi(a[i].time.substr(3, 2));
                       if (hr  >= 9 && hr <= 11 )
                                a[i].fare=30;
                       else if (hr >= 18 && hr <= 22)
                                a[i].fare=30;
                       else 
                                a[i].fare=25;       
                    }
                }
                else if (a[i].toz==2)
                {
                    if(a[i].day=="Monday" || "Tuesday" || "Wednesday" || "Thursday" || "Friday") 
                    {
                       hr = stoi(a[i].time.substr(0, 2));
                       min = stoi(a[i].time.substr(3, 2));
                       if (hr  >= 7 && hr <= 10 && min <= 30)
                                a[i].fare=35;
                       else if (hr >= 17 && hr <= 20)
                                a[i].fare=35;
                       else 
                                a[i].fare=30;                    
                    }  
                    else if(a[i].day=="Saturday" || "Sunday")
                    {
                       hr = stoi(a[i].time.substr(0, 2));
                       min = stoi(a[i].time.substr(3, 2));
                       if (hr  >= 9 && hr <= 11 )
                                a[i].fare=35;
                       else if (hr >= 18 && hr <= 22)
                                a[i].fare=35;
                       else 
                                a[i].fare=30;
                    }
                }
                
                break;

              case 2:
                if (a[i].toz==2)
                {
                    if(a[i].day=="Monday" || "Tuesday" || "Wednesday" || "Thursday" || "Friday") 
                    {
                       hr = stoi(a[i].time.substr(0, 2));
                       min = stoi(a[i].time.substr(3, 2));
                       if (hr  >= 7 && hr <= 10 && min <= 30)
                                a[i].fare=25;
                       else if (hr >= 17 && hr <= 20)
                                a[i].fare=25;
                       else 
                                a[i].fare=20;
                                          
                    }  
                    else if(a[i].day=="Saturday" || "Sunday")
                    {
                       hr = stoi(a[i].time.substr(0, 2));
                       min = stoi(a[i].time.substr(3, 2));
                       if (hr  >= 9 && hr <= 11)
                                a[i].fare=25;
                       else if (hr >= 18 && hr <= 22)
                                a[i].fare=25;
                       else 
                                a[i].fare=20;
                    }
                }
                if (a[i].toz==1)
                {
                    if(a[i].day=="Monday" || "Tuesday" || "Wednesday" || "Thursday" || "Friday") 
                    {
                       hr = stoi(a[i].time.substr(0, 2));
                       min = stoi(a[i].time.substr(3, 2));
                       if (hr  >= 7 && hr <= 10 && min <= 30)
                                a[i].fare=35; 
                       else 
                                a[i].fare=30; 
                    }  
                    else if(a[i].day=="Saturday" || "Sunday")
                    {
                       hr = stoi(a[i].time.substr(0, 2));
                       min = stoi(a[i].time.substr(3, 2));
                       if (hr  >= 9 && hr <= 11)
                                a[i].fare=35;
                       else 
                                a[i].fare=30;
                    }
                }
                break;
             
             default:
                cout<<"Wrong input for zone";
             break;
          }
     } 

for (i=0 ; i < no ; i++)
 {
   t2=t;
   for (i=t+1 ; i < no, flag>=0; i++)
     { 
        if(a[i].day=="Monday")
          total[0]=total[0]+a[i].fare;
        if(a[i].day=="Tuesday")
          total[1]=total[1]+a[i].fare;
        if(a[i].day=="Wednesday")
          total[2]=total[2]+a[i].fare;
        if(a[i].day=="Thursday")
          total[3]=total[3]+a[i].fare;
        if(a[i].day=="Friday")
           total[4]=total[4]+a[i].fare;
        if(a[i].day=="Saturday")
           total[5]=total[5]+a[i].fare;
        if(a[i].day=="Sunday")
        {
            if(a[i+1].day!="Sunday")
            {
               total[6]=total[6]+a[i].fare;
               flag=-1;
               t=i;
            }   
            else
            {
               total[6]=total[6]+a[i].fare;
               flag=0;
            }          
        }
        if (a[i].day=="eof" || a[i].day=="EOF" ||a[i].day=="Eof" ) 
          break;  
     }
      week_check=i;
   for ( i = t2+1; i < week_check ; i++)
    {
      for ( ;i < week_check, a[i].day=="Monday"; i++)
       {
         if (a[i].fromz!=a[i].toz){
             if(total[0]>120)
                total[0]=120;
         }        
         else if (a[i].fromz==a[i].toz){
             if (a[i].fromz==1){
                if(total[0]>100){
                    total[0]=100;
                }    
             }    
             else if (a[i].fromz==2){      
                if(total[0]>80)
                    total[0]=80;
             }        
         }        
        temp=total[0];
        if (temp>f_disc)
            f_disc=temp; 
        new_total[0]=f_disc;
       }
    f_disc=0;    
    for ( ;i < week_check, a[i].day=="Tuesday" ; i++)
     {
       if (a[i].fromz!=a[i].toz){
            if(total[1]>120)
                total[1]=120;
        }        
        else if (a[i].fromz==a[i].toz){
            if (a[i].fromz==1){
                if(total[1]>100)
                    total[1]=100;
            }        
            else if (a[i].fromz==2){
               if(total[1]>80)
                    total[1]=80; 
            }
        }            
        temp=total[1];
        if (temp>f_disc)
            f_disc=temp; 
        new_total[1]=f_disc;

      }
    f_disc=0;
    for ( ;i < week_check, a[i].day=="Wednesday" ; i++)
     {
       if (a[i].fromz!=a[i].toz){
            if(total[2]>120)
                total[2]=120;
        }        
        else if (a[i].fromz==a[i].toz){
            if (a[i].fromz==1){
                if(total[2]>100)
                    total[2]=100;
            }        
            else if (a[i].fromz==2){
               if(total[2]>80)
                    total[2]=80; 
            }
        }            
        temp=total[2];
        if (temp>f_disc)
            f_disc=temp; 
        new_total[2]=f_disc;
      }
    f_disc=0;  
    for (  ;i < week_check, a[i].day=="Thursday" ; i++)
     {
       if (a[i].fromz!=a[i].toz){
            if(total[3]>120)
                total[3]=120;
        }        
        else if (a[i].fromz==a[i].toz){
            if (a[i].fromz==1){
                if(total[3]>100)
                    total[3]=100;
            }        
            else if (a[i].fromz==2){
               if(total[3]>80)
                    total[3]=80; 
            }        
        }                    
        temp=total[3];
        if (temp>f_disc)
            f_disc=temp; 
        new_total[3]=f_disc;
     }
    f_disc=0; 
    for ( ;i < week_check, a[i].day=="Friday" ; i++)
     {
       if (a[i].fromz!=a[i].toz){
            if(total[4]>120)
                total[4]=120;
       }        
        else if (a[i].fromz==a[i].toz){
            if (a[i].fromz==1){
                if(total[4]>100)
                    total[4]=100;
            }        
            else if (a[i].fromz==2){
               if(total[4]>80)
                    total[4]=80; 
            }        
        }            
        temp=total[4];
        if (temp>f_disc)
            f_disc=temp; 
        new_total[4]=f_disc;
     }
    f_disc=0;
    for (;i < week_check, a[i].day=="Saturday"; i++ )
     {
       if (a[i].fromz!=a[i].toz){
            if(total[5]>120)
                total[5]=120;
        }                
        else if (a[i].fromz==a[i].toz){
            if (a[i].fromz==1){
                if(total[5]>100)
                    total[5]=100;
            }        
            else if (a[i].fromz==2){
               if(total[5]>80)
                    total[5]=80; 
            }        
        }
        temp=total[5];
        if (temp>f_disc)
            f_disc=temp; 
        new_total[5]=f_disc;
     }
    f_disc=0;
    for ( ;i < week_check, a[i].day=="Sunday" ; i++)
     { 
       if (a[i].fromz!=a[i].toz){
            if(total[6]>120){
                total[6]=120;
            }
        }        
        else if (a[i].fromz==a[i].toz){
            if (a[i].fromz==1){
                if(total[6]>100)
                    total[6]=100;
            }        
            else if (a[i].fromz==2){
               if(total[6]>80)
                    total[6]=80; 
            } 
        }           
        temp=total[6];
        if (temp>f_disc)
            f_disc=temp; 
        new_total[6]=f_disc;
     }
    f_disc=0; 
  }

 for( j=0;j<7;j++)
    w_fare=w_fare+new_total[j];

 for ( j = 0; j < 7; j++){
    if(new_total[j]==100){
      if(w_fare>500)
        w_fare=500;
    }    
    else if(new_total[j]==120){
      if(w_fare>600)
        w_fare=600;
    }    
    else if(new_total[j]==80){
      if(w_fare>400)
       w_fare=400;  
    }     
  w_temp=w_fare;
    if (w_temp>w_disc)
      w_disc=w_temp; 
 }
 final_fare_calculated=final_fare_calculated+w_disc;
 w_disc=0;
 w_fare=0;
 w_temp=0;
 for ( k = 0; k < 7; k++)
  {  new_total[k]=0;
     total[k]=0;
  }   
 flag=0;
 i=i-2;
}
 cout<<endl<<final_fare_calculated;
 getch();
}