// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Person {
    long long int id;
    char name[100];
    int parent_id;
    double height;
    char eye_color[100];
    int children_count;
    struct Person **children;
    struct Person *parent;
} Person;

void create_Adam(Person *Adam) {
    Adam->id = -1;
    strcpy(Adam->name,"Adam");
    Adam->parent_id = -1;
    Adam->height = 0;
    strcpy(Adam->eye_color," ");
    Adam->children_count = 0;
    Adam->children = NULL;
    Adam->parent = NULL;
}

Person *create_child(int id, char name[], int parent_id, double height, char eye_color[], Person *parent) {
    Person *child = (Person *) malloc(sizeof(Person));
    child->id = id;
    strcpy(child->name, name);
    child->parent_id = parent_id;
    child->height = height;
    strcpy(child->eye_color, eye_color);
    child->children_count = 0;
    child->children = NULL;
    child->parent = parent;
    return child;
}

void add_child(Person *parent, Person *child) {
    if(parent->children_count == 0) {
        parent->children = (Person **) malloc(sizeof(Person *));
    }
    else {
        parent->children = (Person **) realloc(parent->children, (parent->children_count+1)*sizeof(Person *));
    }
    parent->children[parent->children_count] = child;
    parent->children_count += 1;
}

Person *find_person(Person *root, int id) {
    if(root->id == id) {
        return root;
    }
    for(int i=0; i<root->children_count; i++) {
        Person *found = find_person(root->children[i], id);
        if(found) {
            return found;
        }
    }
    return NULL;
}

void Print(Person *person, int level) {
    int copy_level = level;
    while(copy_level > 0) {
        printf("    ");
        copy_level--;
    }
    printf("%s\n", person->name);
    if(person->children_count == 0) {
        return;
    }
    int *arr = malloc(person->children_count*sizeof(int));
    for(int i=0; i<person->children_count; i++) {
        arr[i] = i;
    }
    for(int i=0; i<person->children_count-1; i++) {
        for(int j=i+1; j<person->children_count; j++) {
            if(person->children[arr[i]]->id > person->children[arr[j]]->id) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i=0; i<person->children_count; i++) {
        Print(person->children[arr[i]], level+1);
    }
    free(arr);
}

int is_ancestor(Person *person1, Person *person2) {
    if(person1->id == person2->id) {
        return 1;
    }
    for(int i=0; i<person1->children_count; i++) {
        int found = is_ancestor(person1->children[i], person2);
        if(found) {
            return found;
        }
    }
    return 0;
}

void calculate_weight(Person *person, int *weight) {
    if(person->parent == NULL) {
        return;
    }
    *weight += 1;
    calculate_weight(person->parent, weight);
}

Person *lca(Person *person1, Person *person2, int weight1, int weight2) {
    if(weight1 < weight2) {
        if(person1->id == -1) {
            return NULL;
        }
        if(is_ancestor(person1, person2)) {
            return person1;
        }
        Person *found = lca(person1->parent, person2, weight1-1, weight2);
        if(found) {
            return found;
        }
        return NULL;
    }
    else {
        if(person2->id == -1) {
            return NULL;
        }
        if(is_ancestor(person2, person1)) {
            return person2;
        }
        Person *found = lca(person1, person2->parent, weight1, weight2-1);
        if(found) {
            return found;
        }
        return NULL;
    }
}

void switch_persons(Person *person1, Person *person2) {
    Person temp;
    temp.id = person1->id; strcpy(temp.name,person1->name); temp.parent_id = person1->parent_id;
    temp.height = person1->height; strcpy(temp.eye_color,person1->eye_color);
    temp.children_count = person1->children_count; temp.children = person1->children; temp.parent = person1->parent;

    person1->parent_id = person2->parent_id; person1->parent = person2->parent;
    for(int i=0; i<person2->parent->children_count; i++) {
        if(person2->parent->children[i]->id == person2->id) {
            person2->parent->children[i] = person1;
            break;
        }
    }

    person2->parent_id = temp.parent_id; person2->parent = temp.parent;
    for(int i=0; i<temp.parent->children_count; i++) {
        if(temp.parent->children[i]->id == temp.id) {
            temp.parent->children[i] = person2;
            break;
        }
    }
}

int check_color(int colors_count, char colors[][100], char color[]) {
    for(int i=0; i<colors_count; i++) {
        if(strcmp(colors[i],color) == 0) {
            return 0;
        }
    }
    return 1;
}

void predict_height(Person *person, double *height, double *sum) {
    if(person->id == -1) {
        *height = *height / *sum;
        return;
    }
    int weight = 0; calculate_weight(person, &weight);
    *height += weight*person->height;
    *sum += weight;
    predict_height(person->parent, height, sum);
}

void predict_eye(Person *person, int colors_count, char colors[][100], double *arr, double *sum) {
    if(person->id == -1) {
        for(int i=0; i<colors_count; i++) {
            arr[i] = (arr[i] / *sum)*100;
        }
        return;
    }
    int weight = 0; calculate_weight(person, &weight);
    for(int i=0; i<colors_count; i++) {
        if(strcmp(colors[i],person->eye_color) == 0) {
            arr[i] += weight;
        }
    }
    *sum += weight;
    predict_eye(person->parent, colors_count, colors, arr, sum);
}

int main() {
    Person *Adam = (Person *) malloc(sizeof(Person));
    create_Adam(Adam);
    char command[100];
    int colors_count = 0;
    char colors[100][100];

    while(1) {
        scanf("%s",command);

        if(strcmp(command,"end") == 0) {
            break;
        }

        else if(strcmp(command,"add") == 0) {
            int id; char name[100]; int parent_id; double height; char eye_color[100];
            scanf("%d", &id); scanf("%s", name); scanf("%d", &parent_id); scanf("%lf", &height); scanf("%s", eye_color);
            Person *parent = find_person(Adam, parent_id);
            if(parent) {
                Person *child = create_child(id, name, parent_id, height, eye_color, parent);
                add_child(parent, child);
                if(check_color(colors_count, colors, eye_color)) {
                    strcpy(colors[colors_count], eye_color);
                    colors_count++;
                }
            }
            else {
                printf("Parent doesn't exist!\n");   
            }
        }

        else if(strcmp(command,"print") == 0) {
            int id; scanf("%d", &id);
            Person *person = find_person(Adam, id);
            Print(person, 0);
        }

        else if(strcmp(command,"switch") == 0) {
            int id1; int id2; scanf("%d", &id1); scanf("%d", &id2);
            Person *person1 = find_person(Adam, id1);
            Person *person2 = find_person(Adam, id2);
            if(is_ancestor(person1, person2) || is_ancestor(person2, person1)) {
                printf("You can't switch with an ancestor!\n");
            }
            else if(person1->parent_id == -1 && person2->parent_id == -1) {
                printf("The given IDs are both roots!\n");
            }
            else if(person1->parent_id == person2->parent_id) {
                printf("The given IDs are already siblings!\n");
            }
            else {
                switch_persons(person1, person2);
            }
        }

        else if(strcmp(command,"lca") == 0) {
            int id1; int id2; scanf("%d", &id1); scanf("%d", &id2);
            Person *person1 = find_person(Adam, id1);
            Person *person2 = find_person(Adam, id2);
            int weight1 = 0; int *wieght1_ptr = &weight1; calculate_weight(person1, wieght1_ptr);
            int weight2 = 0; int *wieght2_ptr = &weight2; calculate_weight(person2, wieght2_ptr);
            if(lca(person1, person2, weight1, weight2)) {
                printf("ID: %d NAME: %s\n", lca(person1, person2, weight1, weight2)->id, lca(person1, person2, weight1, weight2)->name);
            }
            else {
                printf("No common ancestor exists!\n");
            }
        }

        else if(strcmp(command,"predict") == 0) {
            int id; scanf("%d", &id);
            Person *person = find_person(Adam, id);
            double *arr = (double *) calloc(colors_count,sizeof(double)); double sum = 0;
            predict_eye(person, colors_count, colors, arr, &sum);
            char max_color[100]; double max_probability = 0;
            for(int i=0; i<colors_count; i++) {
                if(arr[i]>max_probability) {
                    max_probability = arr[i];
                    strcpy(max_color,colors[i]);
                }
                if(arr[i]==max_probability) {
                    if(strcmp(colors[i],max_color) < 0) {
                        strcpy(max_color,colors[i]);
                    }
                }
            }
            max_probability = floor(max_probability*100)/100;
            printf("eye color: %s %.2lf%%\n", max_color, max_probability);

            double height = 0; sum = 0;
            predict_height(person, &height, &sum);
            height = floor(height*100)/100;
            printf("height: %.2lf\n", height);
        }
    }
    
    
    return 0;
}