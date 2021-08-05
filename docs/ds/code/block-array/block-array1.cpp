num = sqrt(n); //块的长度
for (int i = 1; i <= num; i++)
  st[i] = n / num * (i - 1) + 1, ed[i] = n / num * i;
ed[num] = n;//终点, st 数组保存了块的起点. (最后可能不是一个完整的块)
for (int i = 1; i <= num; i++) {
  for (int j = st[i]; j <= ed[i]; j++) {
    belong[j] = i; //表示j号元素属于i块, 打标记
  }
  size[i] = ed[i] - st[i] + 1; //块的大小
}