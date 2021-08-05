void Sort(int k) {
  for (int i = st[k]; i <= ed[k]; i++) t[i] = a[i];
  sort(t + st[k], t + ed[k] + 1);//对t进行排序,也就是a数组,看上面的解析
}
void Modify(int l, int r, int c) { //区间修改
  int x = belong[l], y = belong[r]; //找出哪个块
  if (x == y) { //在一个块里
    for (int i = l; i <= r; i++) a[i] += c;
    Sort(x);
    return;
  }
  //不在一个块里,完整的和不完整的分别处理，左右不完整中间完整
  for (int i = l; i <= ed[x]; i++) a[i] += c;
  for (int i = st[y]; i <= r; i++) a[i] += c;
  for (int i = x + 1; i < y; i++) dlt[i] += c;
  Sort(x);//更新sort得到的值
  Sort(y);
}
int Answer(int l, int r, int c) { //区间查询,大体思路和上面完全一样,建议先好好理解上面的代码
  int ans = 0, x = belong[l], y = belong[r];
  if (x == y) {
    for (int i = l; i <= r; i++)
      if (a[i] + dlt[x] >= c) ans++;
    return ans;
  }
  for (int i = l; i <= ed[x]; i++)
    if (a[i] + dlt[x] >= c) ans++;
  for (int i = st[y]; i <= r; i++)
    if (a[i] + dlt[y] >= c) ans++;
  for (int i = x + 1; i <= y - 1; i++)
    ans += ed[i] - (lower_bound(t + st[i], t + ed[i] + 1, c - dlt[i]) - t) + 1;
  return ans;
}