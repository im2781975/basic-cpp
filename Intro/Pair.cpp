
void determine(int n) {
    vector <pair <pair <string, string>, int >> pr;
    for(int i = 0; i < n; i++) {
        string first, last; int age;
        cin >> first >> last >> age;
        pr.push_back({{first, last}, age});
    }
    for(int i = 0; i < n; i++) 
        cout << pr[i].first.first << " " << pr[i].first.second << " " << pr[i].second << endl;
    
    pair <string, double> Q("abcdef", 1.23);
    pair <string, double> R;
    R = make_pair("Abcdefg", 4.56);
    cout << Q.first + R.first << " " << Q.second + R.second << endl;
    swap(Q, R);
    
    pair <int, int> qr = {1, 3};
    int a, b; tie(a, b) = qr;
    // int a, b; tie(a, ignore) = qr;
    cout << a << " " << b << endl;
    
    pair <int, pair <int, char>> rs = {3, {4, 'a'}};
    int x, y; char z;
    tie(x, ignore) = rs
    tie(y, z) = rs.second;
    cout << x << " " << y << " " << z << endl;
}

