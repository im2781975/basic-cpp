#include <bits/stdc++.h>
using namespace std;
class cuboid{
    int length, weidth, heigth;
    public:
    cuboid(){
        length = 0; weidth = 0, heigth = 0;
    }
    cuboid(int length, int weidth, int heigth){
        this->length = length;
        this->weidth = weidth;
        this->heigth = heigth;
    }
    int GetVolume(){
        return length * weidth * heigth;
    }
    int GetSurfaceArea(){
        return 2 *(heigth*length + heigth*weidth + length*weidth);
    }
    static bool compSur(cuboid a, cuboid b){
       return a.GetSurfaceArea() > b.GetSurfaceArea();
    }
    static bool comvlm(cuboid a, cuboid b){
        return a.GetVolume() < b.GetVolume();
    }
};
bool compSur(cuboid a, cuboid b){
       return a.GetSurfaceArea() > b.GetSurfaceArea();
}
bool compvlm(cuboid a, cuboid b){
        return a.GetVolume() < b.GetVolume();
}
class cube{
    int length, *breadth, heigth;
    public:
    cube(){
        breadth = new int;
    }
    void set(int length, int b, int heigth){
        this->length = length;
        *breadth = b;
        this->heigth = heigth;
    }
    void display(){
        cout << "Length: " << length << "\nbreadth: " << *breadth << "\nheigth: " << heigth;
    }
    cube(const cube &a){
        length = a.length;
        breadth = new int;
        *breadth = *(a.breadth);
        heigth = a.heigth;
    }
    cube operator + (cube &b){
        cube newcube;
        newcube.length = this->length + b.length;
        newcube.breadth = new int;
        *(newcube.breadth) = *(this->breadth) + *(b.breadth);
        newcube.heigth = this->heigth + b.heigth;
        return newcube;
    }
    ~cube(){
        cout << "called";
        //delete breadth;
    }
};
int main(){
    cuboid cub[11];
    int n = 5;
    for(int i = n -1; i >= 0; i--){
        cub[i] = cuboid(i + 10, i + 5, i + 2);
        cout << cub[i].GetVolume() << " " << cub[i].GetSurfaceArea() << "\n";
    }
    cout << "\nSurface:\n";
    sort(cub, cub+n, compvlm);
    for(int i = 0; i < n; i++)
        cout << cub[i].GetVolume() << " " << cub[i].GetSurfaceArea() << "\n";
    
    cout << "\nVolume:\n";
    sort(cub, cub + n, compSur);
    for(int i = 0; i < n; i++)
        cout << cub[i].GetVolume() << " " << cub[i].GetSurfaceArea() << "\n";
        
    cube c, d, e;
    c.set(23, 12, 11);
    c.display();
    d.set(11, 12, 23);
    d.display();
    e = c + d;
    e.display();
}
