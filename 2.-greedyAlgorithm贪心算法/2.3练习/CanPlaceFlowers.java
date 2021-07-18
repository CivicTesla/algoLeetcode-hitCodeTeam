// import java.util.*;
//! java文件固定格式，CanPlaceFlowers与文件同名，该类再包裹主函数
public class CanPlaceFlowers {
    public static void main(String[] args) {

        class Solution {
            //t O(m)O(1)
            public boolean canPlaceFlowers0(int[] flowerbed, int n) {
                int count = 0;
                int m = flowerbed.length;
                int prev = -1;
                for (int i = 0; i < m; i++) {
                    if (flowerbed[i] == 1) {
                        if (prev < 0) {
                            count += i / 2;
                        } else {
                            count += (i - prev - 2) / 2;
                        }
                        if (count >= n) {
                            return true;
                        }
                        prev = i;
                    }
                }
                if (prev < 0) {
                    count += (m + 1) / 2;
                } else {
                    count += (m - prev - 1) / 2;
                }
                return count >= n;
            }
            //t O(m)O(1)
            public boolean canPlaceFlowers1(int[] flowerbed, int n) {
                int count = 0;
                int m = flowerbed.length;
                int prev = -1;
                for (int i = 0; i < m; i++) {
                    if (flowerbed[i] == 1) {
                        if (prev < 0) {
                            count += i / 2;
                        } else {
                            count += (i - prev - 2) / 2;
                        }
                        if (count >= n) {
                            return true;
                        }
                        prev = i;
                    }
                }
                if (prev < 0) {
                    count += (m + 1) / 2;
                } else {
                    count += (m - prev - 1) / 2;
                }
                return count >= n;
            }
        }

        Solution solve =new Solution();
        int[] list = {1,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,1,0,0};
        System.out.println(solve.canPlaceFlowers0(list,1));
        System.out.println(solve.canPlaceFlowers1(list,1));
        System.out.println(new Solution().canPlaceFlowers0(list,1));

        // class ProgramTest {
        //     @Test  //* Test需要通过maven安装，引入项目
        //     public void TestCase1() {
        //         int[] input = {1,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,1,0,0};
        //         boolean expected = true;
        //         var actual = new Solution().canPlaceFlowers0(input,1);
        //         Utils.assertTrue(expected == actual); //* Test单元测试
        //     }
        // }
        
    }
}
