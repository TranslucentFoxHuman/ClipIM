#define _VERSION_CODE_ "1.0.0"

/*
 * ClipIM
 * Copyright (C) 2025 半狐 (半透明狐人間,TlFoxHuman,TranslucentFoxHuman)
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include "mainwindow.h"
#include "var.h"
#include <iostream>
#include <string>
#include <QApplication>

char mode=0;
std::string version = _VERSION_CODE_;

void print_help(void) {
    std::cout << "ClipIM " << _VERSION_CODE_ << "\n"
                 "Copyright (C) 2025 TlFoxHuman(TranslucentFoxHuman, 半狐, 半透明狐人間)\n"
                 "\n"
                 "Usage :\n"
                 "clipim <options>\n"
                 "\n"
                 "Options:\n"
                 "-s : Show single-line input dialog. (default)\n"
                 "-m : Show multi-line input dialog.\n"
                 "-h : Print this help.\n"
                 "-v : Print version information.\n"
              << std::endl;
}

void print_version(void) {
    std::cout << "ClipIM " << _VERSION_CODE_ << "\n"
                 "Copyright (C) 2025 TlFoxHuman(TranslucentFoxHuman, 半狐, 半透明狐人間)\n"
                 "\n"
                 "This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.\n"
                 "\n"
                 "This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.\n"
                 "\n"
                 "You should have received a copy of the GNU General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>." << std::endl;
}

int main(int argc, char *argv[])
{

    if (argc > 1) {
        for (int i=1;i<argc;i++) {
            if (std::string(argv[i]) == "-h" || std::string(argv[i]) == "--help") {
                print_help();
                return 0;
            } else if (std::string(argv[i]) == "-v" || std::string(argv[i]) == "--version") {
                print_version();
                return 0;
            } else if (std::string(argv[i]) == "-s") {
                mode=0;
            } else if (std::string(argv[i]) == "-m") {
                mode=1;
            } else {
                std::cout << "Unrecognized option: " << std::string(argv[i]) << std::endl;
                return 1;
            }
        }
    }
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return a.exec();
}
