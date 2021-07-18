var canPlaceFlowers0 = function(flowerbed, n) {
    let count = 0;
    const m = flowerbed.length;
    let prev = -1;
    for (let i = 0; i < m; i++) {
        if (flowerbed[i] === 1) {
            if (prev < 0) {
                count += Math.floor(i / 2);
            } else {
                count += Math.floor((i - prev - 2) / 2);
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
};
var canPlaceFlowers1 = function(flowerbed, n) {
    let count = 0;
    const m = flowerbed.length;
    let prev = -1;
    for (let i = 0; i < m; i++) {
        if (flowerbed[i] === 1) {
            if (prev < 0) {
                count += Math.floor(i / 2);
            } else {
                count += Math.floor((i - prev - 2) / 2);
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
};

var list=[1,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,1,0,0];
var n = 1;
console.log(canPlaceFlowers0(list,n));
