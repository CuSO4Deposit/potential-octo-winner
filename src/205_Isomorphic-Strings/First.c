// 2 ms (< 76.9%), 5.7 MB (< 80.31%)

bool isIsomorphic(char * s, char * t){
    char map[2][128];   // map[0]: s -> t, map[1]: t -> s
    for (int i = 0; i < 2; i++){ 
        for (int j = 0; j < 128; j++){
            map[i][j] = '\0';
        }
    }

    while (*s){
        if (map[0][(int)(*s)] == '\0' && map[1][(int)(*t)] == '\0'){
            map[0][(int)(*s)] = *t;
            map[1][(int)(*t)] = *s;
        }
        else{
            if (map[0][(int)(*s)] != *t || map[1][(int)(*t)] != *s)
                return false;
        }
        s++;
        t++;
    }
    return true;
}
