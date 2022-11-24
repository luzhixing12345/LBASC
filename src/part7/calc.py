

from spi import Lexer, Parser,BinOp,Num

class NodeVisitor(object):
    def visit(self, node):
        # type(node).__name__ = BinOp / Num
        method_name = 'visit_' + type(node).__name__
        #print(method_name)
        
        # equal to use : self.visit_BinOp(node) / self.visit_Num(node)
        visitor = getattr(self, method_name, self.generic_visit)
        return visitor(node)

    def generic_visit(self, node):
        raise Exception('No visit_{} method'.format(type(node).__name__))


class Interpreter_infix2suffix(NodeVisitor):
    def __init__(self, parser):
        self.parser = parser

    def visit_BinOp(self, node):
        return f'{self.visit(node.left)} {self.visit(node.right)} {node.op.value}'

    def visit_Num(self, node):
        return node.value

    def interpret(self):
        tree = self.parser.parse()
        return self.visit(tree)

class Interpreter_infix2prefix(NodeVisitor):
    def __init__(self, parser):
        self.parser = parser

    def visit_BinOp(self, node:BinOp):
        return f'{node.op.value} {self.visit(node.left)} {self.visit(node.right)}'

    def visit_Num(self, node:Num):
        return node.value

    def interpret(self):
        tree = self.parser.parse()
        return self.visit(tree)

def main():
    
    while True:
        text = input("calc> ")
        lexer = Lexer(text)
        parser = Parser(lexer)
        interpreter_infix2suffix = Interpreter_infix2suffix(parser)
        result_suffix = interpreter_infix2suffix.interpret()
        
        lexer = Lexer(text)
        parser = Parser(lexer)
        interpreter_infix2prefix = Interpreter_infix2prefix(parser)
        result_prefix = interpreter_infix2prefix.interpret()
        
        print("infix input  : ",text)
        print("suffix output: ",result_suffix)
        print("prefix output: ",result_prefix)
        

def test_interface(text):
    
    lexer = Lexer(text)
    parser = Parser(lexer)
    interpreter_infix2suffix = Interpreter_infix2suffix(parser)
    result_suffix = interpreter_infix2suffix.interpret()

    lexer = Lexer(text)
    parser = Parser(lexer)
    interpreter_infix2prefix = Interpreter_infix2prefix(parser)
    result_prefix = interpreter_infix2prefix.interpret()
    
    return (result_suffix,result_prefix)

if __name__ == "__main__":
    main()