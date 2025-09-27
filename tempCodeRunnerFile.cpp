
    while (q--) {
        int q1, u, v;
        cin >> q1 >> u >> v;
        if (q1 == 1) {
            ST.modify(u - 1, v);
        } else {
            cout << ST.query(u - 1, v - 1) << nl;
        }
    }