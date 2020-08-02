from distutils.core import setup, Extension

def main():
    setup(name="MatLib",
          version="1.0.0",
          description="Python interface for the MatLib C++ library",
          author="Mark Oborne",
          ext_modules=[Extension("MatLib", ["pyMatrix.cpp"])])


if __name__ == "__main__":
    main()
