// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#include <math.h>

int main() {
    unsigned long long int num;
    scanf("%llu", &num);

    int count_1 = 0, count_2 = 0, count_3 = 0, count_4 = 0, count_5 = 0, count_6 = 0, count_7 = 0, count_8 = 0;

    int cutter = 255;
    int copy_num = num & cutter;

    if ((copy_num == 0) || (copy_num == 1) || (copy_num == 2) || (copy_num == 4) || (copy_num == 8) || (copy_num == 16) || (copy_num == 32) ||
    (copy_num == 64) || (copy_num == 128)) {
        if (copy_num == 1)
            count_1++;
        else if (copy_num == 2)
            count_2++;
        else if (copy_num == 4)
            count_3++;
        else if (copy_num == 8)
            count_4++;
        else if (copy_num == 16)
            count_5++;
        else if (copy_num == 32)
            count_6++;
        else if (copy_num == 64)
            count_7++;
        else if (copy_num == 128)
            count_8++;
        
        num = num >> 8;
        copy_num = num & cutter;

        if ((copy_num == 0) || (copy_num == 1) || (copy_num == 2) || (copy_num == 4) || (copy_num == 8) || (copy_num == 16) || (copy_num == 32) ||
        (copy_num == 64) || (copy_num == 128)) {
            if (copy_num == 1)
                count_1++;
            else if (copy_num == 2)
                count_2++;
            else if (copy_num == 4)
                count_3++;
            else if (copy_num == 8)
                count_4++;
            else if (copy_num == 16)
                count_5++;
            else if (copy_num == 32)
                count_6++;
            else if (copy_num == 64)
                count_7++;
            else if (copy_num == 128)
                count_8++;

            num = num >> 8;
            copy_num = num & cutter;

            if ((copy_num == 0) || (copy_num == 1) || (copy_num == 2) || (copy_num == 4) || (copy_num == 8) || (copy_num == 16) || (copy_num == 32) ||
            (copy_num == 64) || (copy_num == 128)) {
                if (copy_num == 1)
                    count_1++;
                else if (copy_num == 2)
                    count_2++;
                else if (copy_num == 4)
                    count_3++;
                else if (copy_num == 8)
                    count_4++;
                else if (copy_num == 16)
                    count_5++;
                else if (copy_num == 32)
                    count_6++;
                else if (copy_num == 64)
                    count_7++;
                else if (copy_num == 128)
                    count_8++;

                num = num >> 8;
                copy_num = num & cutter;

                if ((copy_num == 0) || (copy_num == 1) || (copy_num == 2) || (copy_num == 4) || (copy_num == 8) || (copy_num == 16) || (copy_num == 32) ||
                (copy_num == 64) || (copy_num == 128)) {
                    if (copy_num == 1)
                        count_1++;
                    else if (copy_num == 2)
                        count_2++;
                    else if (copy_num == 4)
                        count_3++;
                    else if (copy_num == 8)
                        count_4++;
                    else if (copy_num == 16)
                        count_5++;
                    else if (copy_num == 32)
                        count_6++;
                    else if (copy_num == 64)
                        count_7++;
                    else if (copy_num == 128)
                        count_8++;

                    num = num >> 8;
                    copy_num = num & cutter;

                    if ((copy_num == 0) || (copy_num == 1) || (copy_num == 2) || (copy_num == 4) || (copy_num == 8) || (copy_num == 16) || (copy_num == 32) ||
                    (copy_num == 64) || (copy_num == 128)) {
                        if (copy_num == 1)
                            count_1++;
                        else if (copy_num == 2)
                            count_2++;
                        else if (copy_num == 4)
                            count_3++;
                        else if (copy_num == 8)
                            count_4++;
                        else if (copy_num == 16)
                            count_5++;
                        else if (copy_num == 32)
                            count_6++;
                        else if (copy_num == 64)
                            count_7++;
                        else if (copy_num == 128)
                            count_8++;

                        num = num >> 8;
                        copy_num = num & cutter;

                        if ((copy_num == 0) || (copy_num == 1) || (copy_num == 2) || (copy_num == 4) || (copy_num == 8) || (copy_num == 16) || (copy_num == 32) ||
                        (copy_num == 64) || (copy_num == 128)) {
                            if (copy_num == 1)
                                count_1++;
                            else if (copy_num == 2)
                                count_2++;
                            else if (copy_num == 4)
                                count_3++;
                            else if (copy_num == 8)
                                count_4++;
                            else if (copy_num == 16)
                                count_5++;
                            else if (copy_num == 32)
                                count_6++;
                            else if (copy_num == 64)
                                count_7++;
                            else if (copy_num == 128)
                                count_8++;

                            num = num >> 8;
                            copy_num = num & cutter;

                            if ((copy_num == 0) || (copy_num == 1) || (copy_num == 2) || (copy_num == 4) || (copy_num == 8) || (copy_num == 16) || (copy_num == 32) ||
                            (copy_num == 64) || (copy_num == 128)) {
                                if (copy_num == 1)
                                    count_1++;
                                else if (copy_num == 2)
                                    count_2++;
                                else if (copy_num == 4)
                                    count_3++;
                                else if (copy_num == 8)
                                    count_4++;
                                else if (copy_num == 16)
                                    count_5++;
                                else if (copy_num == 32)
                                    count_6++;
                                else if (copy_num == 64)
                                    count_7++;
                                else if (copy_num == 128)
                                    count_8++;

                                num = num >> 8;
                                copy_num = num & cutter;

                                if ((copy_num == 0) || (copy_num == 1) || (copy_num == 2) || (copy_num == 4) || (copy_num == 8) || (copy_num == 16) || (copy_num == 32) ||
                                (copy_num == 64) || (copy_num == 128)) {
                                    if (copy_num == 1)
                                        count_1++;
                                    else if (copy_num == 2)
                                        count_2++;
                                    else if (copy_num == 4)
                                        count_3++;
                                    else if (copy_num == 8)
                                        count_4++;
                                    else if (copy_num == 16)
                                        count_5++;
                                    else if (copy_num == 32)
                                        count_6++;
                                    else if (copy_num == 64)
                                        count_7++;
                                    else if (copy_num == 128)
                                        count_8++;

                                    if ((count_1 < 2) && (count_2 < 2) && (count_3 < 2) && (count_4 < 2) && (count_5 < 2) && (count_6 < 2) && (count_7 < 2) && (count_8 < 2)) {
                                        printf("NO");
                                    }
                                    else {
                                        printf("YES");
                                    }
                                }
                                else {
                                    printf("YES");
                                }
                            }
                            else {
                                printf("YES");
                            }
                        }
                        else {
                            printf("YES");
                        }  
                    }
                    else {
                        printf("YES");
                    } 
                }
                else {
                    printf("YES");
                }   
            }
            else {
                printf("YES");
            }  
        }
        else {
            printf("YES");
        }
    }
    else {
        printf("YES");
    }

    return 0;
}