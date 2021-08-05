//0x3f3f3f3f3f3f3f3fll 为INF(long long)类型
//总体思路与上个代码相同,若有困难建议复习下上面的代码
void Sort(int k) { //排序找出z
  for (int i = st[k]; i <= ed[k]; i++) t[i] = a[i];
  sort(t + st[k], t + ed[k] + 1);
}
void PushDown(int x) { //总体被赋值了,要把标记下传,类比线段树懒标记
  if (dlt[x] != 0x3f3f3f3f3f3f3f3fll)
    for (int i = st[x]; i <= ed[x]; i++) a[i] = t[i] = dlt[x];
  dlt[x] = 0x3f3f3f3f3f3f3f3fll;
}
void Modify(int l, int r, int c) { //区间修改
  int x = belong[l], y = belong[r];
  PushDown(x); //类比线段树懒标记
  if (x == y) {//与上个代码完全相同
    for (int i = l; i <= r; i++) a[i] = c;
    Sort(x);
    return;
  }
  PushDown(y);
  for (int i = l; i <= ed[x]; i++) a[i] = c;
  for (int i = st[y]; i <= r; i++) a[i] = c;
  Sort(x);
  Sort(y);
  for (int i = x + 1; i < y; i++) dlt[i] = c;
}
int Binary_Search(int l, int r, int c) { //二分查找
  int ans = l - 1, mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if (t[mid] <= c)
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  return ans;
}
int Answer(int l, int r, int c) { //区间查询,与上份代码完全相同,增加了下传和二分操作
  int ans = 0, x = belong[l], y = belong[r];
  PushDown(x);
  if (x == y) {
    for (int i = l; i <= r; i++)
      if (a[i] <= c) ans++;
    return ans;
  }
  PushDown(y);
  for (int i = l; i <= ed[x]; i++)
    if (a[i] <= c) ans++;
  for (int i = st[y]; i <= r; i++)
    if (a[i] <= c) ans++;
  for (int i = x + 1; i <= y - 1; i++) {
    if (0x3f3f3f3f3f3f3f3fll == dlt[i])
      ans += Binary_Search(st[i], ed[i], c) - st[i] + 1;
    else if (dlt[i] <= c)
      ans += size[i];
  }
  return ans;
}