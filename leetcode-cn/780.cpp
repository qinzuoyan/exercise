class Solution {
public:
  bool reachingPoints(int sx, int sy, int tx, int ty) {
    bool changed = true;
    while (changed) {
      changed = false;
      if (tx > ty) {
        if (tx - sx >= ty) {
          tx = sx + (tx - sx) % ty;
          changed = true;
        }
      }
      else if (tx < ty) {
        if (ty - sy >= tx) {
          ty = sy + (ty - sy) % tx;
          changed = true;
        }
      }
    }
    return sx == tx && sy == ty;
  }
};
