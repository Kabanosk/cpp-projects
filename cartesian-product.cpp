void cartesian_prodacts(std::string firstArr[], int sizeOfFirstArr, std::string secondArr[], int sizeOfSecondArr, std::string cartesianProdacts[][2]) {
    int i = 0;
    for (int k = 0; k < sizeOfFirstArr*sizeOfSecondArr; k++) {
        cartesianProdacts[k][0] = firstArr[i];
        cartesianProdacts[k][1] = secondArr[k%sizeOfSecondArr];

        std::cout << cartesianProdacts[k][0];
        std::cout << cartesianProdacts[k][1] << std::endl;

        if (k%sizeOfSecondArr == sizeOfSecondArr - 1) {
            i++;
        }
    }
}
