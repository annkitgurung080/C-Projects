#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char contractId[100];
    char client[100];
    char contractor[100];
    int value;
    int isComplete;
} Contract;

int createContract(Contract contracts[], int contractCount) {
    char client[100], contractor[100], contractId[100];
    int value;

printf("Enter Client Name: ");
scanf("%s", client);
printf("Enter Contractor Name: ");
scanf("%s", contractor);
printf("Enter Contract Value: ");
scanf("%d", &value);
printf("Enter Contract Id: ");
scanf("%s", contractId);

    contracts[contractCount].value = value;
    contracts[contractCount].isComplete = 0;
strcpy(contracts[contractCount].client, client);
strcpy(contracts[contractCount].contractor, contractor);
strcpy(contracts[contractCount].contractId, contractId);

contractCount++;

    return contractCount;
}
int main() {
    int contractCount = 0;
    Contract contracts[100];
    // Add your contract management code here
    return 0;
}
