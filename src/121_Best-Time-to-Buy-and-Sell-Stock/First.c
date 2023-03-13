// 133 ms (< 93.83%), 13 MB (< 60.41%)

int maxProfit(int* prices, int pricesSize){
	int max[pricesSize];

	max[pricesSize - 1] = prices[pricesSize - 1];
	for (int i = pricesSize - 2; i >= 0; i--){
		max[i] = (prices[i] > max[i + 1]) ? prices[i] : max[i + 1];
	}

	int profit = 0;
	for (int i = 0; i < pricesSize; i++){
		profit = (profit < max[i] - prices[i]) ? max[i] - prices[i] : profit;
	}

	return profit;
}
