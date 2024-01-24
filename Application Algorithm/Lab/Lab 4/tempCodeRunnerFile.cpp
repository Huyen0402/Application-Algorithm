
        if(hd.empty()) f[i] = a[i];
        else f[i] = hd.top().first + a[i];
        res = max(f[i], res);