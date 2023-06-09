char * gcdOfStrings(char * str1, char * str2){
	int maxcommon = 0;
	for (int i = 2; i <= strlen(str1) / 2; i++){
		if (strlen(str1) % i == 0 && strlen(str2) % 2 == 0){
			int num = strlen(str1) / i;
			int flag = 1;
			for (int j = 0; j < i; j++){
				if (flag == 0){
					break;
				}
				for (int k = 0; k < num; k++){
					if (str1[j + k] != str1[j]){
						flag = 0;
					}
				}
			}
			// reaches here means str1[0..num-1] is a divisor of str1
			num = strlen(str2) / i;
			for (int j = 0; j < i; j++){
				if (flag == 0){
					break;
				}
				for (int k = 0; k < num; k++){
					if (str2[j + k] != str1[j]){
						flag = 0;
					}
				}
			}
			// reaches here means str1[0..num-1] is a common divisor
			maxcommon = i;
		}
	}
	char* common_divisor = (char*)malloc(maxcommon * sizeof(char));
	for (int i = 0; i < maxcommon; i++){
		common_divisor[i] = str1[i];
	}
	return common_divisor;
}
