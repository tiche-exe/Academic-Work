Parameter A B C : Prop.
Lemma example : A /\ B -> B /\ A.
Proof.
intro H.
destruct H as [H0 H1].
split.
exact H1.
exact H0.
Qed.

Lemma example1 : A /\ B -> B /\ A.
Proof.
intro H.
elim H.
intros.
split.
exact H1.
exact H0.
Qed.

Lemma q1: ((A /\ B) /\ C) -> (A /\ (B /\ C)).
Proof.
intro H.
elim H.
intros.
split.
apply H.
split.
apply H.
exact H1.
Qed.

Lemma q2: ((A /\ B) -> C) -> (A -> (B -> C)).
intro H.
intro H1.
intro H2.
apply H.
split.
exact H1.
exact H2.
Qed.

Lemma q3: ((A \/ B) \/ C) -> (A \/ (B \/ C)).
Proof.
intro H.
elim H.
intro H1.
elim H1.
left.
exact H0.
right.
left.
exact H0.
right.
right.
exact H0.
Qed.

Lemma q4: ((A \/ B) -> C) -> (A -> (B -> C)).
intro H.
intro H1.
intro H2.
apply H.
right.
apply H2.
Qed.

Lemma q5: (~A \/ B) -> (A -> B).
Proof.
intro H.
intro H1.
elim H.
intro H0.
contradiction.
intro H0.
exact H0.
Qed.

Lemma q6: (A -> B) -> (~B -> ~A).
Proof.
intro H.
intro H1.
intro H2.
apply H1.
apply H.
exact H2.
Qed.

Lemma q7: ~(A /\ ~A).
Proof.
intro H.
destruct H as [H0 H1].
contradiction.
Qed.