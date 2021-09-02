#pragma once

#ifndef EXCEPTION_LTD
#define EXCEPTION_LTD

namespace ltd {
    class exception {
    public:
        virtual char* what() = 0;
    };

    class logic_error : public exception {
        char* chr;
    public:
        logic_error(char* _chr) {
            chr = _chr;
        }
        logic_error(const char* _chr) {
            chr = (char*)_chr;
        }

        char* what() override final {
            return chr;
        }
    };

    class invalid_argument : public logic_error {
    public:
        invalid_argument(char* _chr) : logic_error(_chr) {}
        invalid_argument(const char* _chr) : logic_error(_chr) {}
    };
    class domain_error : public logic_error {
    public:
        domain_error(char* _chr) : logic_error(_chr) {}
        domain_error(const char* _chr) : logic_error(_chr) {}
    };
    class length_error : public logic_error {
    public:
        length_error(char* _chr) : logic_error(_chr) {}
        length_error(const char* _chr) : logic_error(_chr) {}
    };
    class out_of_range : public logic_error {
    public:
        out_of_range(char* _chr) : logic_error(_chr) {}
        out_of_range(const char* _chr) : logic_error(_chr) {}
    };
}
#endif