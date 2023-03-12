// 4 ms (< 20.66%), 5.5 MB (< 98.73%)

bool isSubsequence(char * s, char * t){
    char* ps = s - 1;
    char* pt = t - 1;
    do{
        while (*(++ps) == *(++pt) && *pt)
            ;
        while (*pt && *(++pt) != *(ps))
            ;
    } while(*pt);
    return !(*ps);
}
