//
//  main.c
//  hackerrank_common-child
//
//  Created by ernesto alvarado on 23/07/19.
//  Copyright © 2019 ernesto alvarado. All rights reserved.
//

// XXX: https://www.martinkysel.com/hacker-rank-common-child-solution/
// XXX: https://codereview.stackexchange.com/questions/127448/high-execution-time-of-lcs-length-program-in-python2
// XXX: https://www.hackerrank.com/rest/contests/master/challenges/common-child/hackers/kira/download_solution?primary=true

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a,b) (a>b?a:b)
#define ord(c) (c-'A')
#define MAX_LEN 5000
#define ALFABETO_TAM (ord('Z')+1)
int dp[MAX_LEN+1][MAX_LEN+1]={0};
short ultima_posicion[MAX_LEN][ALFABETO_TAM]={[0 ... MAX_LEN-1]={[0 ... ALFABETO_TAM-1]=-1}};

//#define DEBUGH
// Complete the commonChild function below.
int commonChild(char* s1, char* s2) {
    int s1_len=strlen(s1);
    int s2_len=strlen(s2);
    for(int i=0;i<s1_len;i++){
        char c=s1[i];
        int i_ant=i?i-1:i;
        for(int j=0;j<ALFABETO_TAM;j++){
            ultima_posicion[i][j]=ultima_posicion[i_ant][j];
        }
        ultima_posicion[i][ord(c)]=i;
    }
#ifdef DEBUGH
    for(int j=0;j<ALFABETO_TAM;j++){
        printf("% 2c ",'A'+j);
    }
    printf("\n");
    for(int i=0;i<s1_len;i++){
        char c=s1[i];
        for(int j=0;j<ALFABETO_TAM;j++){
            printf("%02d ",ultima_posicion[i][j]);
        }
        printf("\n");
    }
#endif
    for(int i=0;i<s1_len;i++){
        for(int j=0;j<s2_len;j++){
            char cj=s2[j];
            short up=ultima_posicion[i][ord(cj)];
            int dpt =dp[i+1][j];
            if(up!=i){
                /*
                if(up==-1){
                    up=i;
                }
                dpt=max(dp[up][j]+1,dpt);
                 */
                                dpt=max(dp[i][j+1],dpt);
            }
            else{
                dpt=dp[i][j]+1;
            }
            dp[i+1][j+1]=dpt;
        }
    }
    
#if 0
    for(int i = 0; i < s1_len;i++) {
        for(int j = 0; j < s2_len;j++) {
            int dpt=dp[i+1][j];
            if(s1[i] != s2[j]) {
                dpt=max(dp[i][j+1], dpt);
            } else {
                dpt = dp[i][j] + 1;
            }
            dp[i+1][j+1]=dpt;
        }
    }
    
#endif
    
    
#ifdef DEBUGH
    for(int i=0;i<=s1_len;i++){
        for(int j=0;j<=s2_len;j++){
            printf("% 4d",dp[i][j]);
        }
        printf("\n");
    }
#endif
    return dp[s1_len][s2_len];
}



int main()
{
    char a[MAX_LEN],b[MAX_LEN];
    scanf("%s%s",a,b);
    int r=commonChild(a, b);
    printf("%d\n",r);
    return 0;
}

