/*  Mituram ray
    Roll: 13045409
*/

#include<bits/stdc++.h>
#include<string.h>
#include<conio.h>

using namespace std;

void LCM();
void Random();
void chi_test();
void Run_Up_Down();
void Run_Above_Below();
void Poker_test();

int main(){

 char ch;

    L:
    printf("\n\n\t0 => Generate Random Number.\n \t1 => Perform frequency Test . \n \t2 => Perform Independence Test.\n \t......others to exit\n\n \tEnter...");

    ch = getche();

    switch(ch){
        case '0':
            char r;
            L2: printf("\n\n\tEnter .......\n\t\t l => Random Number By LCM.\n\t\t r => Random Number By Build in Method.\n\n\tEnter.....");
            r=getche();

            if(r=='l')
                LCM();
            else if(r=='r')
                Random();
            else
                goto L2;

         goto L;
         break;

        case '1':
            //char f;
            L3: printf("\n\n\tEnter Test Name.....\n \t\t c => Perform Chi- Test.\n \t\tEnter...");
            r=getche();
             if(r=='c')
                chi_test();
             else
                goto L3;

         goto L;
         break;  //.....
        case '2':
            L4: printf("\n\nEnter Test Name.....\n \t\t u => Perform Run Up/Down Test.\n \t\t a => Perform Run Above/Below Test.\n \t\t p => Perform Poker's Test.\n \t\tEnter...");
            r=getche();
            if(r=='u')
                Run_Up_Down();
            else if(r=='a')
                Run_Above_Below();
            else if(r=='p')
                Poker_test();
                //printf("\n\n\tPoker Test");
            else
                goto L4;

         goto L;
         break; //.....
        default:
            return 0;
            break;
    }

 return 0;
}

void LCM(){
    int n,seed,mul,inc,mod;

    printf("\n\tEnter no. of Random Number: ");
    scanf("%d",&n);

    printf("\n\tEnter Seed: ");
    scanf("%d",&seed);

    printf("\n\tEnter constant multiplier: ");
    scanf("%d",&mul);

    printf("\n\tEnter increment: ");
    scanf("%d",&inc);

    printf("\n\tEnter modulus: ");
    scanf("%d",&mod);

    FILE *out = fopen("input.txt","w");

    fprintf(out,"%d\n",n);


    for(int i =0;i<n;i++){
        seed = (seed*mul + inc)%mod;

        fprintf(out,"%d\n",seed);
    }

    fclose(out);
    system("cls");
    printf("\nRandom Number Generated By LCM......\n");

}

void Random(){
    int n;
    printf("\n\tEnter no. of Random Number: ");
    scanf("%d",&n);

    FILE *out = fopen("input.txt","w");

    fprintf(out,"%d\n",n);


    for(int i =0;i<n;i++){
       fprintf(out,"%d\n",rand()%1000);
    }

    fclose(out);

    system("cls");
    printf("\nRandom Number Generated By Random Stream......\n");

}

void chi_test(){

    int rn,clss,highest,number,ev=500;
    int value_of_each_class,low,high,observed_Value[100],first_range[100],last_range[100];
    double min,max,v1,v2,X=0;

    FILE *in = fopen("input.txt","r");
    FILE *out = fopen("output.txt","w");

    printf("\n\tEnter no. of class to divide the range:" );
    scanf("%d",&clss);

    printf("\n\tEnter the highest value : ");
    scanf("%d",&highest);

    printf("\n\tEnter the range : ");
    scanf("%lf%lf",&min,&max);

    fscanf(in,"%d",&rn);

    fprintf(out,"Total no.of random number  : %d\n",rn);
    fprintf(out,"No.of classes : %d\n",clss);
    fprintf(out,"Modulus : %d\n",highest);

    fprintf(out,"Chi-Square Range : %lf to %lf \n\n",min,max);

    value_of_each_class = ceil((double)highest/clss);

    low=0;
    high = value_of_each_class-1;

    for(int i=0; i<clss; i++){
     observed_Value[i] = 0;
    }

    for(int i=0; i<clss; i++){
       first_range[i] = low;

       last_range[i] = high;

       low = value_of_each_class+low  ;

       high = value_of_each_class+high ;
    }

    for(int i=0;i<rn;i++){
        fscanf(in,"%d",&number);

        for(int j=0;j<clss;j++){
           if(number>=first_range[j] && number<=last_range[j]){
                observed_Value[j]++;
                break;
            }
        }
    }

    fprintf(out,"\nRange\tObserved value(Oi)\tExpected value(Ei)\t(Oi-Ei)^2\t(Oi-Ei)^2/Ei\n");
    fprintf(out,"------   -----------------       ---------------  \t---------     -----------\n");
     for(int i=0; i<clss;i++){
        v1 = observed_Value[i]-ev;
        v1 = v1*v1;
        v2 = (double)v1/ev;

        X = X + v2;
        fprintf(out,"%d %d\t\t%d\t\t\t%d\t\t%lf\t%lf\n",first_range[i], last_range[i],observed_Value[i],ev,v1,v2);
    }

    if(X>=min  && X<=max )
        fprintf(out,"\nChi-Square value %lf  is accepted !",X);
    else
        fprintf(out,"\nChi-Square value %lf  is not accepted !",X);

        fclose(in);
        fclose(out);
        system("cls");
        printf("\nFrequency Test is Completed.....\n");

}

void Run_Up_Down(){

    FILE *in = fopen("input.txt","r");
    FILE *out = fopen("output.txt","w");

    char ch1,run[1000];
    double alpha,range,mean,variance,Z;
    int run_no=0;
    int rno,temp,random[5000];

    printf("\n\n\tEnter significance: ");
    scanf("%lf",&alpha);

    fscanf(in,"%d",&rno);

    alpha = alpha/2;

    if(alpha == 0.1000)
        range = 1.28;
    else if(alpha == 0.0500)
        range = 1.64;
    else if(alpha == 0.0250)
        range = 1.96;
    else if(alpha == 0.0100)
        range = 2.33;
    else if(alpha == 0.0050)
        range = 2.58;
    else if(alpha == 0.0025)
        range = 2.81;
    else if(alpha == 0.0010)
        range = 3.09;

    fscanf(in,"%d",&random[0]);
    temp = random[0];

    for(int i=1;i<rno;i++){

       fscanf(in,"%d",&random[i]);

        if(temp<random[i])
            run[i-1] = '+';
        else
            run[i-1] = '-';

          temp = random[i];
    }

    for(int i=0;i<rno-1;i++){
        ch1 = run[i];

        while( ch1 == run[i+1])
            i++;

            run_no++;
    }

    fprintf(out,"Total random number : %d\n",rno);

    fprintf(out,"\nTotal run number : %d\n\n",run_no);

    for(int i=0;i<strlen(run);i++)
      fprintf(out,"%c  ",run[i]);

    fprintf(out,"\n");
    mean = (double)(2*rno-1)/3;
    variance = (double)(16*rno-29)/90;

    fprintf(out,"\nThe mean : %lf\n",mean);

    fprintf(out,"\nThe variance : %lf\n",variance);

    Z = (run_no-mean)/sqrt(variance);

    if(Z>=-range && Z<=range)
        fprintf(out,"\nSince Z = %lf , the independence of the numbers can not be rejected !\n", Z);
    else
        fprintf(out,"\nSince Z = %lf , the independence of the numbers can be rejected !\n", Z);

    fclose(in);
    fclose(out);
    system("cls");
    printf("\nRun Up\Down Test is Completed.....\n");
}

void Run_Above_Below(){

    FILE *in = fopen("input.txt","r");
    FILE *out = fopen("output.txt","w");

    char ch1,run[1000];
    double alpha,range,Z,mean,mean1,variance;
    int run_no=0,n1=0,n2=0,N;
    int rno,temp,random[5000];

    printf("\n\n\tEnter significance: ");
    scanf("%lf",&alpha);

    fscanf(in,"%d",&rno);

    mean = (0 + rno-1)/2;


    alpha = alpha/2;

    if(alpha == 0.1000)
        range = 1.28;
    else if(alpha == 0.0500)
        range = 1.64;
    else if(alpha == 0.0250)
        range = 1.96;
    else if(alpha == 0.0100)
        range = 2.33;
    else if(alpha == 0.0050)
        range = 2.58;
    else if(alpha == 0.0025)
        range = 2.81;
    else if(alpha == 0.0010)
        range = 3.09;

    temp = mean;

    for(int i=0;i<rno;i++){

        fscanf(in,"%d",&random[i]);

        if(temp<random[i]){
            run[i-1] = '+';
            n1++;
        }
        else{
            run[i-1] = '-';
            n2++;
        }
    }

    for(int i=0;i<rno-1;i++){
        ch1 = run[i];

        while( ch1 == run[i+1])
            i++;

        run_no++;
    }

    fprintf(out,"Total random number : %d\n",rno);
    fprintf(out,"The mean value :%lf\n",mean);

    fprintf(out,"\nThe observation above mean:%d\n",n1);
    fprintf(out,"The observation below mean:%d\n",n2);
    fprintf(out,"\nTotal run number : %d\n\n",run_no);

    N=n1+n2;

    for(int i=0;i<strlen(run);i++)
        fprintf(out,"%c  ",run[i]);

   fprintf(out,"\n");
    mean1 = (2*n1*n2)/N+0.5;
    variance = (2*n1*n2)*(2*n1*n2-N)/(N*N*(N-1));

    fprintf(out,"\nThe mean : %lf\n",mean1);

    fprintf(out,"\nThe variance : %lf\n",variance);

    Z = (rno-mean1)/sqrt(variance);

    if(Z>=-range && Z<=range)
        fprintf(out,"\nSince Z = %lf , the independence of the numbers can not be rejected !\n", Z);
    else
        fprintf(out,"\nSince Z = %lf , the independence of the numbers can be rejected !\n", Z);

    fclose(in);
    fclose(out);
    system("cls");
    printf("\nRun Above\Below Test is Completed.....\n");
}

void Poker_test(){

    FILE *in = fopen("input.txt","r");
    FILE *out = fopen("output.txt","w");
    FILE *out2 = fopen("output2.txt","w");

    int ch2[3],expect[3];
    int rno,number,observed_Value[1000];
    double min,max,v1,v2,X=0;


    printf("\n\tEnter the range : ");
    scanf("%lf%lf",&min,&max);

    fscanf(in,"%d",&rno);

    fprintf(out,"Total no.of random number  : %d\n",rno);

    fprintf(out,"Chi-Square Range : %lf to %lf \n\n",min ,max );

    for(int i=0; i<3; i++){
        observed_Value[i] = 0;
    }

    int nnn=32;
    for(int i=0;i<rno;i++){
      fscanf(in,"%d",&number);
        for(int j=2;j>=0;j--){
            ch2[j] = number%10;
            number=number/10;
            fprintf(out2,"%d",ch2[j]);
        }
        fprintf(out2,"\n\n");

    if(ch2[0] == ch2[1] && ch2[0] == ch2[2])
        observed_Value[0]++;  //all same
    else if(ch2[0] !=ch2[1] && ch2[0] != ch2[2] && ch2[1] != ch2[2])
        observed_Value[1]++;  //all different
    else
        observed_Value[2]++;  //any pair same
    }

    expect[0] = 0.01*rno;  //all same
    expect[1] = 0.72*rno;  //all different
    expect[2] = 0.27*rno;  // any pair same

    char *st[3];
        st[0]="All Same";
        st[1]="All Different";
        st[2]="Any Pair Same";

    fprintf(out,"\n  Type\t\tObserved value(Oi)\tExpected value(Ei)\t(Oi-Ei)^2\t(Oi-Ei)^2/Ei\n");
    fprintf(out," -----        ----------------------       ---------------  \t---------     -----------\n");
    for(int i=0; i<3; i++){

        v1 = observed_Value[i]-expect[i];
        v1 = v1*v1;
        v2 = (double)v1/expect[i];

        X = X + v2;

        fprintf(out,"%s\t\t%d\t\t\t%d\t\t%.3lf\t\t%.3lf\n",st[i],observed_Value[i],expect[i],v1,v2);
    }

    if(X>=min  && X<=max )
        fprintf(out,"\nChi-Square value %lf  is accepted !",X);
    else
        fprintf(out,"\nChi-Square value %lf  is not accepted !",X);



    fclose(in);
    fclose(out);
    fclose(out2);
    system("cls");
    printf("\nPoker's Test is completed.....\n");

}
