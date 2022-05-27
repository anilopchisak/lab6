#pragma once

#include <string>
#include <map>
#include <vector>

#include "glfxClasses.h"

using namespace std;
using namespace glfxParser;

enum SamplerParam {
    SAMPLER_PARAM_STRING,
    SAMPLER_PARAM_INT,
    SAMPLER_PARAM_FLOAT
};

enum RegisterParamType {
    REGISTER_NONE,
    REGISTER_INT,
    REGISTER_NAME
};

struct glfxstype {
    glfxstype() {}

    struct variable {
        string  prepend;
        string  type;
        string  identifier;
    };

    struct samplerVar {
        string  binding;
        string  name;
    };

    union {
        int num;
        unsigned unum;
        int lineno;
        float fnum;
        bool boolean;
        Program* prog;
        Sampler* samp;
        map<ShaderType, Program::Shader>* shaders;
        vector<variable>* vars;
        vector<samplerVar>* texNames;
    };
    
    union {
        SamplerParam samplerParamType;
        ShaderType sType;
        RegisterParamType rType;
    };

    // Carrying these around is bad luck, or more like bad performance. But whatever...
    string strs[3];
};

namespace glfxParser {
extern bool gLexPassthrough;

#ifdef LINUX
int fopen_s(FILE** pFile, const char *filename, const char *mode);
#endif

}

#define YYSTYPE glfxstype

#if 0
#define YYDEBUG 1
extern int glfxdebug;
#endif

string glfxreadblock(unsigned char openChar, unsigned char closeChar);
void glfxerror(const char*);
int glfxparse();
