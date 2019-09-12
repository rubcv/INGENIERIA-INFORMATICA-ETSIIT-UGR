from flask import Flask, render_template

app = Flask(__name__)


@app.route('/')
def hello_world():
    pag = '''
        <html> 
            <head>
                <title>P2 - DAI </title>
            </head>

            <body>  
                <h1 style="color:blue;"> Practica 2 - DAI</h1> 
                <img src="https://www.popsci.com/sites/popsci.com/files/styles/1000_1x_/public/images/2018/03/senna.jpg?itok=eYNPMGjA&fc=50,50">
            </body>
        </html>
    '''
    return pag

@app.route('/usuario/<nombre>')
def usuario_nombre(nombre):
    pag = '''
        <html> 
            <head>
                <title>P2 - DAI </title>
            </head>

            <body>  
                <h1 style="color:blue;"> Practica 2 - DAI</h1> 
                <h1 style="color: #2ecc71;"> Hola ''' + nombre + '''</h1> 
                <img src="https://www.popsci.com/sites/popsci.com/files/styles/1000_1x_/public/images/2018/03/senna.jpg?itok=eYNPMGjA&fc=50,50">
            </body>
        </html>
    '''
    return pag

@app.route('/usuario')
def usuario():
    pag = '''
        <html> 
            <head>
                <title>P2 - DAI </title>
            </head>

            <body>  
                <h1 style="color:blue;"> Practica 2 - DAI</h1> 
                <h1 style="color: #2ecc71;"> Hola</h1> 
                <img src="https://www.popsci.com/sites/popsci.com/files/styles/1000_1x_/public/images/2018/03/senna.jpg?itok=eYNPMGjA&fc=50,50">
            </body>
        </html>
    '''
    return pag

def page_not_found(error):
    pag = '''
        <html> 
            <head>
                <title>P2 - DAI </title>
            </head>

            <body>  
                <h1 style="color: #2ecc71;"> Página no encontrada </h1> 
            </body>
        </html>
    '''
    return pag

if __name__ == '__main__':
    app.debug = True
    app.run(host='0.0.0.0')
