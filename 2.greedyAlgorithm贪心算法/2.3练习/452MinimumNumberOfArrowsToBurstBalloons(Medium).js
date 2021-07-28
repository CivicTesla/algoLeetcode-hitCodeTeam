// ! 452. 用最少数量的箭引爆气球
// ! 在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。由于它是水平的，所以纵坐标并不重要，因此只要知道开始和结束的横坐标就足够了。开始坐标总是小于结束坐标。
// ! 
// ! 一支弓箭可以沿着 x 轴从不同点完全垂直地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。 弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。
// ! 
// ! 给你一个数组 points ，其中 points [i] = [xstart,xend] ，返回引爆所有气球所必须射出的最小弓箭数。
// t O(nlogn)|O(logn)
// t 时间复杂度：O(nlogn)+O(n)，其中 n 是数组points 的长度。排序的时间复杂度为 O(nlogn),对所有气球进行遍历并计算答案的时间复杂度为 O(n)，其在渐进意义下小于前者，因此可以忽略。
// t 空间复杂度：O(logn)，即为排序需要使用的栈空间。
var findMinArrowShots = function(points) {
    if (!points.length ) {
        return 0;
    }

    points.sort((a, b) => a[1] - b[1]);//按每个气球的右边界曾序排序；排序的时间复杂度为O(nlogn),栈空间O(logn)
    let pos = points[0][1]
    let ans = 1;
    for (let balloon of points) {//循环获取points的元素给balloon
        if (balloon[0] > pos) {//如果气球的左边界大于pos，将该气球的右边界设置为pos，箭ans+1
            pos = balloon[1];
            ans++;
        }
    }
    return ans;
};
var points = new Array([10,16],[2,8],[1,6],[7,12]);
console.log(findMinArrowShots(points));


//!! 最近新增了Test Case， [[-2147483646,-2147483645],[2147483646,2147483647]] 
//!! 就过不了了，这是因为差值过大而产生溢出。sort的时候不要用a-b来比较，要用Integer.compare(a, b)!!!