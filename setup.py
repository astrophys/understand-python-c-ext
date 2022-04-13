from setuptools import setup, Extension


setup(
    name='hellopymod',
    version='1.0',
    description='Python Package with Hello World C Extension',
    ext_modules=[
        Extension(
            'hellopymod',
            sources=['src/hello-world.c'],
            py_limited_api=True)
    ],
)
