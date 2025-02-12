
struct hash_pair {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);
            return hash1 ^ hash2;
        }
    };
class MovieRentingSystem {
public:
    unordered_map<int, set<pair<int, int>>> available; // {movie -> {price, shop}}
    set<pair<int, pair<int, int>>> rentedMovies; // {price, {shop, movie}}
    unordered_map<pair<int, int>, int, hash_pair> shopMoviePrice; // {(shop, movie) -> price}

    

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            available[movie].insert({price, shop});
            shopMoviePrice[{shop, movie}] = price;
        }
    }

    vector<int> search(int movie) {
        vector<int> result;
        if (available.find(movie) == available.end()) return result;
        
        int count = 0;
        for (auto& [price, shop] : available[movie]) {
            result.push_back(shop);
            if (++count == 5) break;
        }
        return result;
    }

    void rent(int shop, int movie) {
        int price = shopMoviePrice[{shop, movie}];

        // Remove from available
        available[movie].erase({price, shop});

        // Add to rented
        rentedMovies.insert({price, {shop, movie}});
    }

    void drop(int shop, int movie) {
        int price = shopMoviePrice[{shop, movie}];

        // Remove from rented
        rentedMovies.erase({price, {shop, movie}});

        // Add back to available
        available[movie].insert({price, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> result;
        int count = 0;
        for (auto& [price, shop_movie] : rentedMovies) {
            int shop = shop_movie.first, movie = shop_movie.second;
            result.push_back({shop, movie});
            if (++count == 5) break;
        }
        return result;
    }
};
