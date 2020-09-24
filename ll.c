#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ll_node{
    int data;
    struct ll_node *next;
}ll_node_t;

struct ll_node* insert_at_start(ll_node_t *head, int data){
    ll_node_t *new_node = (ll_node_t*)calloc(1, sizeof(ll_node_t));
    new_node->data = data;
    new_node->next = NULL;
    
    if(!head){
        return new_node;
    }
    new_node->next = head;
    return new_node;
}

struct ll_node* insert_at_end(ll_node_t *head, int data){
    ll_node_t *temp = head;
    ll_node_t *new_node =(ll_node_t*)calloc(1, sizeof(ll_node_t));
    new_node->data = data;
    new_node->next = NULL;
    
    if(!head)
        return new_node;
        
    while(head->next != NULL){
        head = head->next;
    }
    head->next = new_node;
    return temp;
}

struct ll_node* delete_at_start(ll_node_t *head){
    if (!head){
        printf("No elements in the list\n");
        return head;
    }
    ll_node_t *temp = head;
    head = head->next;
    temp->next = NULL;
    free(temp);
    return head;
}

struct ll_node* delete_at_end(ll_node_t *head){
    if (!head){
        printf("No elements in the list\n");
        return head;
    }
    
    if (head->next == NULL){
        free(head);
        return NULL;
    }
    ll_node_t *parse, *temp = head;
    
    while(temp->next != NULL){
        parse = temp;
        temp = temp->next;
    }
    
    parse->next = NULL;
    free(temp);
    return head;
}

struct ll_node* delete_ele(ll_node_t *head, int data){
    ll_node_t *parse, *temp = head;
    if (!head){
        printf("No elements in the list\n");
        return head;
    }
    if (head->data == data){
        head= head->next;
        temp->next = NULL;
        free(temp);
        return head;
    } 
        
    while(temp != NULL){
        if(temp->data == data){
            parse->next = temp->next;
            temp->next = NULL;
            free(temp);
            break;
        }
        parse = temp;
        temp = temp->next;
    }
    
    return head;
}

bool search_node(ll_node_t *head, int data){
    if (!head){
        printf("No elements in the list\n");
        return false;
    }
    if (head->next == NULL && head->data == data){
        return true;
    }

    while(head){
        if(head->data == data){
            return true;
        }
        head=head->next;
    }

    return false;
}

ll_node_t* reverse(ll_node_t *head){
    ll_node_t *temp;
    if(head==NULL || head->next == NULL){
        return head;
    }
    
    temp = reverse(head->next);
    head->next->next=head;
    head->next = NULL;
    
    return temp;
}

void print_ll(ll_node_t *head){
    if(!head)
        return;
    
    while(head){
        printf("%d->", head->data);
        head=head->next;
    }
    printf("\n");
}

int main(){
    int ch, data;
    ll_node_t *head = NULL;

    
    while(1){
        printf( "\n\n"
                "1. add at start\n"
                "2. add at end\n"
                "3. del at start\n"
                "4. del at end\n"
                "5. search and del\n"
                "6. Search\n"
                "7. reverse\n"
                "8. Print\n"
                "9. exit\n"
                "Enter choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1: 
                printf("Enter value to insert: ");
                scanf("%d", &data);
                head = insert_at_start(head, data);
                break;
                
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                head = insert_at_end(head, data);
                break;
                
            case 3:
                head = delete_at_start(head);
                break;
                
            case 4:
                head = delete_at_end(head);
                break;
                
            case 5:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                head = delete_ele(head, data);
                break;
                
            case 6:
                printf("Enter value to search: ");
                scanf("%d", &data);
                if(search_node(head, data)){
                    printf("Node present");
                }
                else{
                    printf("Node not present");
                }
                break;
                
            case 7:
                head = reverse(head);
                break;
                
            case 8:
                print_ll(head);
                break;
                
            case 9:
                exit(0);
        }
    }
}