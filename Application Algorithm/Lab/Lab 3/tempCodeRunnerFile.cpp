cin >> N >> C;

    for(int i = 1; i <= N; i++) {
        cin >> x[i];
    }

    sort(x + 1, x + N + 1);

    l = 1, r = (x[N] - x[1]) / (C - 1), res = 1;

    while(l <= r) {
        mid = (l + r)/2;
        if(check(mid)) {
            l = mid + 1;
            res = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << res << "\n";