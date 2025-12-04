#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <ctime>

using namespace std;

struct Ticket {
    int id;
    string title;
    string description;
    string status; // "Open", "In Progress", "Resolved"
    string priority; // "Low", "Medium", "High"
    string createdDate;
    
    void display() const {
        cout << "ID: " << id << " | Title: " << title 
             << " | Status: " << status << " | Priority: " << priority << endl;
    }
};

class TicketManager {
private:
    vector<Ticket> tickets;
    int nextId = 1;
    
public:
    void createTicket(const string& title, const string& desc, const string& priority) {
        Ticket t = {nextId++, title, desc, "Open", priority, getCurrentDate()};
        tickets.push_back(t);
        cout << "✓ Ticket #" << t.id << " created successfully!\n";
    }
    
    void viewAllTickets() const {
        if (tickets.empty()) {
            cout << "No tickets found.\n";
            return;
        }
        cout << "\n--- All Tickets ---\n";
        for (const auto& t : tickets) t.display();
    }
    
    void updateStatus(int id, const string& newStatus) {
        auto it = find_if(tickets.begin(), tickets.end(), 
                         [id](const Ticket& t) { return t.id == id; });
        if (it != tickets.end()) {
            it->status = newStatus;
            cout << "✓ Ticket #" << id << " updated to " << newStatus << "\n";
        } else {
            cout << "✗ Ticket not found.\n";
        }
    }
    
    void deleteTicket(int id) {
        auto it = find_if(tickets.begin(), tickets.end(), 
                         [id](const Ticket& t) { return t.id == id; });
        if (it != tickets.end()) {
            tickets.erase(it);
            cout << "✓ Ticket #" << id << " deleted.\n";
        } else {
            cout << "✗ Ticket not found.\n";
        }
    }
    
private:
    string getCurrentDate() const {
        time_t now = time(nullptr);
        return ctime(&now);
    }
};

void displayMenu() {
    cout << "\n=== Network Ticket Management ===\n"
         << "1. Create Ticket\n"
         << "2. View All Tickets\n"
         << "3. Update Ticket Status\n"
         << "4. Delete Ticket\n"
         << "5. Exit\n"
         << "Choose option: ";
}

int main() {
    TicketManager manager;
    int choice;
    
    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1: {
                string title, desc, priority;
                cout << "Title: ";
                getline(cin, title);
                cout << "Description: ";
                getline(cin, desc);
                cout << "Priority (Low/Medium/High): ";
                getline(cin, priority);
                manager.createTicket(title, desc, priority);
                break;
            }
            case 2:
                manager.viewAllTickets();
                break;
            case 3: {
                int id;
                string status;
                cout << "Ticket ID: ";
                cin >> id;
                cin.ignore();
                cout << "New Status (Open/In Progress/Resolved): ";
                getline(cin, status);
                manager.updateStatus(id, status);
                break;
            }
            case 4: {
                int id;
                cout << "Ticket ID: ";
                cin >> id;
                manager.deleteTicket(id);
                break;
            }
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid option.\n";
        }
    }
}
