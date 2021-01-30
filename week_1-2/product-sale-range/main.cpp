//
// Created by Andrew Slesarenko on 24/12/2020.
//

#include "iostream"

int main() {
    float n_product_price;
    float a_price_range;
    float x_sale_percent;

    float b_price_range;
    float y_sale_percent;

    std::cin >> n_product_price >> a_price_range >> b_price_range >> x_sale_percent >> y_sale_percent;

    float final_sum;
    float final_sale_percent = 0;

    if (n_product_price > a_price_range) {
        final_sale_percent = x_sale_percent;
    }

    if (n_product_price > b_price_range) {
        final_sale_percent = y_sale_percent;
    }

    if (final_sale_percent) {
        final_sum = n_product_price - n_product_price / 100 * final_sale_percent;
    } else {
        final_sum = n_product_price;
    }


    std::cout << final_sum;

    return 0;
}