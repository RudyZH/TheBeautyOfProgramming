int Count(BYTE v) {
    int num = 0;
    while(v) {
      v &= (v - 1);
      num++;
    }
    return num;
}
