#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

struct Place {
    double time, desire;
    std::string name;
    Place(std::string name, double time, double desire) : time(time), desire(desire), name(name) { }
   void Renames(std::string namet, double timet, double desiret)
    {
       name = namet;
       time = timet;
       desire = desiret;
    }
};



std:: vector<Place> findingway(int W,std::vector<Place> Path, int n)

{
    W *= 10;
    double** mas = new  double*[n];
    for (int i = 0; i <= n; i++)
    {
        mas[i] = new double[W*10];
    }
    for (int i = 0; i <= n; i++)
    {
        mas[i][0] = 0;

    }
    for (int i = 0; i <= W*10; i++)
    {
        mas[0][i] = 0;

    }
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (Path[i-1].time*10 <= w) {
                int temp = w - Path[i - 1].time * 10;
                mas[i][w] = std::max(mas[i - 1][w], mas[i - 1][temp] + Path[i - 1].desire);
            }
            else {
                mas[i][w] = mas[i - 1][w];
            }
        }
    }
    std::vector<Place> result;
    int w = W;
    for (int i = n; i > 0 && w >= 0; i--) {
        if (mas[i][w] !=mas[i - 1][w]) {
            result.push_back(Path[i-1]);
            w -= Path[i - 1].time * 10;
        }
    }
   // reverse(result.begin(), result.end());
    return result;
}




void main()
{
    int W = 2; 
    std::vector<Place> mas;
    Place temp("Kreml'", 0.5, 10);
    mas.push_back(temp);
   temp.Renames("Bolshoy Teatr'", 0.3, 7);
    mas.push_back(temp);
    temp.Renames("Zoopark'", 0.6, 3);
    mas.push_back(temp);
    temp.Renames("Tret'yakovskaya galerea'", 0.3, 9);
    mas.push_back(temp);
    temp.Renames("Mavzoley", 0.1, 8);
    mas.push_back(temp);
    temp.Renames("GUM", 0.2, 6);
    mas.push_back(temp);
    temp.Renames("Arbat", 0.3, 8);
    mas.push_back(temp);
    temp.Renames("Luzhniky", 0.4, 7);
    mas.push_back(temp);
    temp.Renames("Moskva city", 0.1, 5);
    mas.push_back(temp);
    temp.Renames("VDNX", 0.2, 6);
    mas.push_back(temp);
    temp.Renames("Vorobievy Gori", 0.3, 5);
    mas.push_back(temp);
    int n = mas.size()-1;
    std::cout << "\n";
    std::vector<Place> final=findingway(W, mas, n) ;
    for (int i = 0; i < final.size(); i++)
    {
        std::cout << final[i].name <<" "<<final[i].desire<< " "<<final[i].time<<"\n";
  }
    int all=0;
    double timer=0;
    for (int i = 0; i < final.size(); i++)
    {
        all += final[i].desire;
        timer += final[i].time;

    }
    std::cout << all << " " << timer;
    
    
}