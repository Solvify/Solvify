class Solution {
    public static String toLowerCase(String str) {
		StringBuilder res = new StringBuilder();
		for (char ch : str.toCharArray()) {
			if (ch >= 65 && ch <= 91)
				res.append((char) (ch+32));
			else
				res.append(ch);
		}
		return res.toString();
	}

    public static final void main(String[] args) {
		System.out.println(toLowerCase("LOVELY"));
	}
}