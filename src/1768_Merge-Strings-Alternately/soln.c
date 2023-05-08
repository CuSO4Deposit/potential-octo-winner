char * mergeAlternately(char * word1, char * word2){
	char* merged = (char*)malloc((strlen(word1) + strlen(word2) + 1) * sizeof(char));
	char* p = word1;
	char* q = word2;
	char* r = merged;
	int i = 0;
	while (*p != '\0' && *q != '\0'){
		if (i % 2 == 0){
			*r++ = *p++;
		}
		else{
			*r++ = *q++;
		}
		++i;
	}
	while (*p != '\0'){
		*r++ = *p++;
	}
	while (*q != '\0'){
		*r++ = *q++;
	}
	*r = '\0';
	return merged;
}
