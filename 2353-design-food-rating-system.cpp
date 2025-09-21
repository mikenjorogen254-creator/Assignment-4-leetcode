class FoodRatings {
    std::unordered_map<std::string, std::string> foodToCuisine;
    std::unordered_map<std::string, int> foodToRating;
    std::unordered_map<std::string, std::set<std::pair<int, std::string>>> cuisineRatings;

public:
    FoodRatings(std::vector<std::string>& foods, std::vector<std::string>& cuisines, std::vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
            cuisineRatings[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(std::string food, int newRating) {
        std::string cuisine = foodToCuisine[food];
        int oldRating = foodToRating[food];
        cuisineRatings[cuisine].erase({-oldRating, food});
        cuisineRatings[cuisine].insert({-newRating, food});
        foodToRating[food] = newRating;
    }
    
    std::string highestRated(std::string cuisine) {
        return cuisineRatings[cuisine].begin()->second;
    }
};
