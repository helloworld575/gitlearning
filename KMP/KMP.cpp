#include<iostream>
#include<string.h>
#include<stdlib.h>

#define max(a,b) (a>b?a:b)

using namespace std;
char s1[200], s2[200];
int nex[200];

void getnext(){
	memset(nex, 0, sizeof(nex));
	int i = -1, j = 0;
	nex[0] = -1;
	while (j < strlen(s2)){
		if (i == -1 || s2[i] == s2[j]){
			j++; i++;
			nex[j] = i;
		}
		else
			i = nex[i];
	}
}

int KMP(){
	int i = 0, j = 0, len1 = strlen(s1), len2 = strlen(s2);
	while ((i < len1) && (j < len2)){
		if (j == -1 || s1[i] == s2[j]){
			i++; j++;
		}
		else
			j = nex[j];
	}
	if (j == len2)
		return i - len2;
	else
		return -1;
}
int index_KMP(){
	int i = 0, j = 0, len1 = strlen(s1), len2 = strlen(s2), re = 0;
	while (i < len1&&j < len2){
		if (j == -1 || s1[i] == s2[j]){
			i++; j++;
		}
		else
			j = nex[j];
		re = max(re, j);
	}
	return re;
}

int main(){
	cin >> s1;
	cin >> s2;
	getnext();
	printf("%d %d", KMP(), index_KMP());
	getchar();
	getchar();
}
