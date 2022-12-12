num = 0;

      while (num <= 2) {
        cout << "How many set of data you want (At least 3): ";
        cin >> num;
      }

      cin.ignore();
      cout << "Enter the professor's name: ";
      getline(cin, name);
      string name2 = pds.find(name)->get_data()->get_name();

      if (name != name2) {
        cout << "Enter the professor's subject: ";
        getline(cin, sub);

        l = new professor[num];

        for (i = 0; i < num; i++) {
          l[i] = create_professor(l2, name, sub, i);
        }

        pds.insert(l, num);
        q.enqueue(l, num);
        num = 0;
        break;
      }

      do {

        cout << "There's already Professor " << name << " in the dataset.\n"
             << endl;

        cout << "Enter the professor's name: ";
        getline(cin, name);
      } while (name == pds.find(name)->get_data()->get_name());

      cout << "Enter the professor's subject: ";
      getline(cin, sub);

      l = new professor[num];

      for (i = 0; i < num; i++) {
        l[i] = create_professor(l2, name, sub, i);
      }

      pds.insert(l, num);
      q.enqueue(l, num);
      num = 0;
      break;