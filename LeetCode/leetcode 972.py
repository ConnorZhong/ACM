def get_two_part(s):
    s_prex = s.split('(')[0];
    
    if len(s.split('(')) > 1:
        s_repeat = s.split('(')[1].split(')')[0]; 
    else:
        s_repeat = '0'
        
    if '.' not in list(s_prex):
        s_prex += '.'
    return s_prex, s_repeat
    
def special(s1,s2,t1,t2):
        s1 = s1 + s2*100
        t1 = t1 + t2*100
        return float(s1)==float(t1)
        
class Solution(object):
    def isRationalEqual(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """
        s1, s2 = get_two_part(S);
        t1, t2 = get_two_part(T);
        if (special(s1,s2,t1,t2)):
            return True
        else:
            return False
