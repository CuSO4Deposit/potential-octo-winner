// 58 ms(< 36.44%), 10.2 MB(< 13.83%)

int updateDptable(int* coins, int coinsSize, int amount, int* dptable){
    for(int i = 0; i <= amount; i++){
        if(dptable[i] != -2)
            continue;
        int allLeavesFailFlag = 1;
        int minLeaf = 0x7fffffff;
        for(int j = 0; j < coinsSize; j++){
            int idx = i - coins[j];
            if(idx < 0)
                continue;
            if(dptable[idx] != -1 && dptable[idx] < minLeaf){
                minLeaf = dptable[idx];
                allLeavesFailFlag = 0;
            }
        }
        if(allLeavesFailFlag)
            dptable[i] = -1;
        else
            dptable[i] = minLeaf + 1;
    }
    return 0;
}

int coinChange(int* coins, int coinsSize, int amount){
    int* dptable = (int*)malloc((amount + 1) * sizeof(int));
    int mincoin = coins[0];
    for(int i = 0; i <= amount; i++)
        dptable[i] = -2;
    for(int i = 0; i < coinsSize; i++){
        if(coins[i] > amount)
            continue;
        dptable[coins[i]] = 1;
        if(coins[i] < mincoin)
            mincoin = coins[i];
    }
    for(int i = 1; i < mincoin && i <= amount; i++)
        dptable[i] = -1;
    dptable[0] = 0;
    updateDptable(coins, coinsSize, amount, dptable);
    return dptable[amount];
}


